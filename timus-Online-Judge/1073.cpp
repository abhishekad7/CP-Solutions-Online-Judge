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
const ll MOD = 1e9+7;
const ll inf = 1e15+7;


ll dp[60007];
ll p;

ll solve(int n){
	
	if(n < 0) return inf;
	
	if(n == 0) return 0;
	
	if(n == 1) return 1;
	
	ll &ret = dp[n];
	if(ret != -1) return ret;
	
	ll ans = inf;
	
	for(ll i = 1; i <= p; i++){
		ans = min(ans, 1 + solve(n - (i * i)));
	}
	
	return ret = ans;
	
}


int main(){
	fast;
	ll n;
	cin>>n;
	p = sqrt(n);
	memset(dp, -1, sizeof(dp));
	ll ans = solve(n);
	
	cout<<ans<<'\n';
	
	return 0;
}
