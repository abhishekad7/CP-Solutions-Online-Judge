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
const ll inf = 2e9;

ll a, fa, b, fb, n;

ll chk(ll fa_1){
	ll res = fa + fa_1;
	ll one = fa_1, two = fa, z;
	for(int i = a+1; i <= b-2; i++){
		z = one+two;
		res+=z;
		//if(res > fb-fa) return false;
		one = two;
		two = z;
	}
	
	return res;
	
}


int main(){
	fast;
	cin>>a>>fa>>b>>fb>>n;
	
	if(a > b){
		swap(a,b);
		swap(fa, fb);
	}
	
	//debug2(a, b);
	
	ll fa_1;
	
	ll lo = -inf, hi = inf+1;
	while(lo < hi){
		ll mid = (lo + hi)>>1;
		//debug3(lo, hi, mid);
		ll cpk = chk(mid);
		if(cpk <= fb - fa || fa - mid < -inf){
			lo = mid+1;
			if(cpk == fb - fa){
				
				fa_1 = mid;
			}
		} else {
			hi = mid;
		}
	}
	
	
	//debug2(fa_1, fa);
	
	if(n == a){
		cout<<fa<<'\n';
		return 0;
	}
	
	if(n < a){
		//cerr<<"if\n";
		int suf = a-1;
		ll two = fa+fa_1;
		ll one = fa;
		ll z;
		while(suf >= n){
			//debug(suf);
			z = two - one;
			two = one;
			one = z;
			suf--;
		}
		
		cout<<z<<'\n';
	} else {
		//cerr<<"else\n";
		int suf = a+1;
		ll two = fa;
		ll one = fa_1;
		ll z;
		while(suf <= n){
			//debug(suf);
			z = two + one;
			one = two;
			two = z;
			suf++;
		}
		
		cout<<z<<'\n';
	}
	
	
	return 0;
}
