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

int a[102][102], presum[102][102];

int main(){
	fast;
	int n;
	cin>>n;
	int allneg = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin>>a[i][j];
			if(a[i][j] >= 0) allneg = 0;
			presum[i][j] = presum[i][j-1] + a[i][j];
		}
	}
	
	int ans = 0;
	if(allneg){
		ans = -22299;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				ans = max(ans, a[i][j]);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			int cur = 0, mx = 0;
			
			for(int k = 1; k <= n; k++){
				int ele = presum[k][j] - presum[k][i -1];
				cur += ele;
				mx = max(cur, mx);
				if(cur < 0) cur = 0;
			}
			
			ans = max(ans, mx);
		}
		
	}
	
	cout<<ans<<'\n';
	
	
	return 0;
}
