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

const int N = 1e6+7;
const int MOD = 1e9+7;
const ll INF = 2e18+7;

vector<int> fibo, prime;
vector<int> pows;
bool isprime[1002];


void fill_fibo(int n){
	fibo[0] = 1;
	fibo[1] = 1;
	
	for(int i = 2; i <= n; i++){
		fibo[i] = (fibo[i-1] + fibo[i-2]) % MOD;
	}
}

void sieve(int n){
	
	for(int i = 2; i < 1002; i++) isprime[i] = 1;
	
	for(int i = 2; i < 1002; i++){
		if(isprime[i]){
			for(int j = 2 * i; j < 1002; j+=i){
				isprime[j] = 0;
			}
		}
	}
	
	for(int i = 2; i < 1002; i++){
		if(isprime[i]) prime.pb(i);
	}
	
}

ll mul(ll a, ll b){
	a = a * b;
	
	while(a >= MOD) a -= MOD;
	
	return a;
}

void fill_pows(int x, ll itnibaar){
	
	int i = 0;
	ll cnt;
	while(i < (int)prime.size() && prime[i] * prime[i] <= x){
		cnt = 0;
		while(x % prime[i] == 0){
			cnt++;
			x/=prime[i];
		}
		if(cnt){
			pows[prime[i]] = (pows[prime[i]] + (mul(cnt, itnibaar)))%MOD;
		}
		i++;
	}
	
	if(x!=1){
		pows[x] = (pows[x] + itnibaar) % MOD;
	}
	
}


int main(){
	fast;
	int n;
	cin>>n;
	fibo.resize(n+1);
	fill_fibo(n);
	pows.resize(n+1, 0);
	sieve(n);
	ll kitnibaar;
	
	
	for(int i = 2; i <= n; i++){
		kitnibaar = fibo[n - i];
		fill_pows(i, kitnibaar);
	}
	
	ll ans = 1;
	
	for(int i = 2; i <= n; i++){
		ans = (ans * ((pows[i] + 1))) % MOD;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
