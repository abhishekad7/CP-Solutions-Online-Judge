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


ll dp[50005][3];
ll n, a, b;



int main(){
	fast;
	dp[0][1] = 1;
	dp[0][2] = 1;
	
	//memset(dp, -1, sizeof(dp));
	cin>>n>>a>>b;
	
	ll ans = 0;
	
	for(int i = 0; i <= n; i++){
		
		for(int j = 1; j<=a && i+j<=n; j++){
			dp[i+j][1] = (dp[i+j][1] + dp[i][2]) % MOD;
		}
		
		for(int j = 1; j<=b && i+j<=n; j++){
			dp[i+j][2] = (dp[i+j][2] + dp[i][1]) % MOD;
		}
		
	}
	
	ans = (dp[n][1] + dp[n][2]) % MOD;
	
	cout<<ans<<'\n';
	
	return 0;
}
