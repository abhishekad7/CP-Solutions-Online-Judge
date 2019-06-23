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

const ll N = 1e4+7;
const ll MOD = 1e9+7;

ll g[N],f[N];
ll pf[N], pg[N];


int main(){
	fast;
	ll n, p;
	while(1){
		cin>>n>>p;
		if(n == 0 && p == 0) break;
		g[1] = pg[1] = 1;
		f[1] = pf[1] = 1;
		
		for(int i = 2; i < n; i++){
			g[i] = (2 * pg[i - 1] + 1) % p;
			g[i] = (g[i] - ((g[i-1] * g[i-1]) % p) + p)%p;
			pg[i] = (g[i] + pg[i-1]) % p;
		}
		
		for(int i = 2; i <= n; i++){
			f[i] = (pf[i-1] + 1)%p;
			pf[i] = (pf[i-1] + ((f[i] * g[i]) % p)) % p;
		}
		
		cout<<f[n]<<'\n';
		
	}
	
	return 0;
}
