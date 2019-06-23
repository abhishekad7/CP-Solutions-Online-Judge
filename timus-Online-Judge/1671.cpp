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

struct S{
	int u, v, valid;
};

vector<int> par;

int root(int x){
	while(par[x] != x){
		par[x] = par[par[x]];
		x = par[x];
	}
	
	return x;
}

void merge(int u, int v){
	u = root(u);
	v = root(v);
	par[u] = par[v];
	
}

int main(){
	fast;
	int n, m;
	cin>>n>>m;
	vector<S> edges(m);
	int u, v;
	for(int i = 0; i < m; i++){
		cin>>u>>v;
		edges[i] = {u, v, 1};
	}
	
	int q;
	cin>>q;
	vector<int> qry(q);
	for(int i = 0; i < q; i++){
		cin>>qry[i];
		qry[i]--;
		edges[qry[i]].valid = 0;
	}
	par.resize(n+1);
	for(int i = 0; i <= n; i++) par[i] = i;
	
	for(int i = 0; i < m; i++){
		u = edges[i].u;
		v = edges[i].v;
		if(edges[i].valid){
			merge(u,v);
		}
	}
	
	set<int> st;
	for(int i = 1; i <= n; i++){
		st.insert(root(i));
	}
	
	int tot = (int)st.size();
	
	vector<int> ans;
	reverse(all(qry));
	for(auto qr: qry){
		ans.pb(tot);
		
		u = edges[qr].u;
		v = edges[qr].v;
		if(root(u) != root(v)){
			merge(u,v);
			tot--;
		}
		
	}
	
	reverse(all(ans));
	for(auto x: ans) cout<<x<<' ';
	cout<<'\n';
	
	return 0;
}
