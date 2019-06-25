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
const ll INF = 2e18+7;

int main(){
	fast;
	int n;
	cin>>n;
	
	int mx = 2;
	while((mx * (mx +1))/2 <= n){
		mx++;
		//debug(mx);
	}
	
	vector<int> ans[mx];
	ans[0].pb(1);
	ans[1].pb(1);
	
	int curr = 2;
	for(int i = 2; i < mx; i++){
		for(int j = 0; j < i; j++){
			ans[j].pb(curr);
			ans[i].pb(curr);
			curr++;
		}
	}
	
	cout<<mx<<'\n';
	for(int i = 0; i < mx; i++){
		cout<<(int)ans[i].size()<<' ';
		for(auto x: ans[i]) cout<<x<<' ';
		cout<<'\n';
	}
	
	return 0;
}
