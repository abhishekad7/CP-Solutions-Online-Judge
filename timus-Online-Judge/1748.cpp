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

ll power(ll a, ll b){
	ll res = 1;
	
	while(b){
		if(b & 1) res *= a;
		
		a = a * a;
		b >>= 1;
	}
	
	return res;
}


ll primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
ll n;
ll qi[16];
ll tmp;


// recursive fundtion to check all combinations of first 12 prime numbers
pair<ll, ll> solve(int pos, int last, ll mx, ll prod){
	if(pos >= 12){
		return {mx, prod};
	}
	
	pair<ll, ll> aux, ans = {-1, INF};
	
	for(int i = 0; i <= last; i++){
		tmp = power(primes[pos], i);
		if(tmp <= n/prod){
			aux = solve(pos+1, i, mx * (i + 1), prod * tmp);
		} else {
			return ans;
		}
		if(aux.fi > ans.fi){
			ans = aux;
		} else if(aux.fi == ans.fi && aux.se < ans.se){
			ans = aux;
		}
	}
	
	return ans;
	
}

int main(){
	fast;
	int t;
	cin>>t;
	pair<ll, ll> ans;
	while(t--){
		cin>>n;
		ans = solve(0, 10, 1, 1);
		cout<<ans.se<<' '<<ans.fi<<'\n';
	}	
	return 0;
}
