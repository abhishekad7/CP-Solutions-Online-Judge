#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define debug(x) cerr<<#x<<" -> "<<x<<'\n'
#define debug2(x,y) cerr<<#x<<" -> "<<x<<" "<<#y<<" -> "<<y<<'\n'
#define debug3(x,y,z) cerr<<#x<<" -> "<<x<<" "<<#y<<" -> "<<y<<" "<<#z<<" -> "<<z<<'\n'

 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<ll , null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>

const ll N = 2e5+7;
const ll MOD = 1e9;
const ll INF = 2e18+7;

ll a[N];
ll ftree[11][N];
int n;


ll sum(int ch, int pos){
	ll sm = 0;
	while(pos > 0){
		//cerr<<"sum\n";
		sm = (sm + ftree[ch][pos]) % MOD;
		pos -= (pos & -pos);
	}
	
	return sm;
}

ll getsum(int ch, int l, int r){
	ll sm = sum(ch, r);
	sm = (sm - sum(ch, l - 1) + MOD) % MOD;
	
	return sm;
}

void upd(int ch, int pos, ll val){
	while(pos <= n){
		//cerr<<"upd\n";
		ftree[ch][pos] = (ftree[ch][pos] + val)%MOD;
		pos += (pos & -pos);
	}
}


int main(){
	fast;
	int k;
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	
	for(int i = 1; i <= n; i++){
		upd(1, a[i], 1);
		
		for(int j = 2; j <= k; j++){
			upd(j, a[i], getsum(j-1, a[i]+1, n));
		}
	}
	
	ll ans = getsum(k, 1, n);
	cout<<ans<<'\n';
	
	return 0;
}
