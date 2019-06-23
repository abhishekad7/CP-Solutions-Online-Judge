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

const ll N = 5e4+7;
const ll MOD = 1e9+7;

pair<ll, ll> depth[N];
vector<pair<int, ll>> edges[N];
ll lift[N][21];

int walk(int node, int moves){
	for(int i = 0; i < 21; i++){
		if(moves & (1 << i)){
			node = lift[node][i];
		}
	}
	return node;
}

void dfs(int s, int p){
	lift[s][0] = p;
	for(int i = 1; i < 21; i++){
		lift[s][i] = lift[lift[s][i-1]][i-1];
	}
	
	for(auto v: edges[s]){
		if(v.fi == p) continue;
		depth[v.fi].fi = depth[s].fi+1;
		depth[v.fi].se = depth[s].se + v.se;
		dfs(v.fi,s);
	}
	
}

//lca return lowesr common ancestor of i ans j

int lca(int i, int j){
	if(depth[i].fi > depth[j].fi){
		i = walk(i, depth[i].fi - depth[j].fi);
	}
	
	if(depth[j].fi > depth[i].fi){
		j = walk(j, depth[j].fi - depth[i].fi);
	}
	
	if(i == j) return i;
	
	for(int k = 20; k >= 0; k--){
		if(lift[i][k] != lift[j][k]){
			i = lift[i][k];
			j = lift[j][k];
		}
	}
	
	return lift[i][0];
}

int main(){
	fast;
	int n;
	cin>>n;
	int u, v;
	ll w;
	for(int i = 1; i < n; i++){
		cin>>u>>v>>w;
		edges[u].pb({v, w});
		edges[v].pb({u, w});
	}
	
	dfs(0, 0);
	
	int q;
	cin>>q;
	int i, j, k;
	ll ans;
	while(q--){
		cin>>u>>v;
		i = u;
		j = v;
		
		k = lca(i, j);
		ans = depth[u].se + depth[v].se - 2 * depth[k].se;
		
		cout<<ans<<'\n';
		
	}
	
	
	return 0;
}
