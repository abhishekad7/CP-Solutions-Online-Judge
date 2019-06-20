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
string s;
int n;
int chk[4004][4004];
int dp[4004];
int nxt[4004];


void fill_chk(int l, int r){
	
	if(r <= l) return;
	
	if(chk[l][r] != -1) return;
	
	if(l + 1 == r){
		if(s[l] == s[r]){
			chk[l][r] = 1;
		} else {
			chk[l][r] = 0;
		}
		return;
	}
	
	fill_chk(l, r-1);
	fill_chk(l+1, r);
	
	if(s[l] == s[r] && chk[l+1][r-1] == 1){
		chk[l][r] = 1;
	} else {
		chk[l][r] = 0;
	}
	
}

int main(){
	fast;
	cin>>s;
	n = (int)s.length();
	memset(chk, -1, sizeof(chk));
	
	for(int i = 0; i < n; i++){
		chk[i][i] = 1;
	}
	
	fill_chk(0, n-1);
	
	for(int i = 1; i <= n; i++) dp[i] = 1000005;
	
	dp[n] = 0;
		
	for(int i = n-1; i >= 0; i--){
		dp[i] = dp[i+1] + 1;
		nxt[i] = i;
		
		for(int j = i+1; j<n; j++){
			if(chk[i][j] == 1){
				dp[i] = min(dp[i], dp[j + 1] + 1);
				if(dp[i] == dp[j+1] + 1){
					nxt[i] = j;
				}
			}
		}
	}
	
	cout<<dp[0] <<'\n';
	
	/*for(int i = 0; i <= n; i++) cerr<<dp[i]<<' ';
	cout<<'\n';
	
	for(int i = 0; i < n; i++) cerr<<nxt[i]<<' ';
	cout<<'\n';*/
	
	//cout<<dp[n] <<'\n';
	
	int i = 0;
	while(i < n){
		int r = nxt[i];
		//debug2(i, r);
		for(int j = i; j <= r; j++){
			cout<<s[j];
		}
		cout<<' ';
		i = r + 1;
	}
	
	cout<<'\n';
	
	return 0;
}
