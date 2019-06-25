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

const ll N = 1e5+7;
const ll MOD = 1e9+7;
const ll INF = 2e18+7;

int nxt[N], visited[N];
stack<int> tstk;
int indeg[N];
set<pair<int, int>> tocall;
vector<int> edges[N];

void dfs1(int s){
	
	visited[s] = 1;
	if(!visited[nxt[s]]){
		dfs1(nxt[s]);
	}
}


void dfs2(int s){
	
	visited[s] = 1;
	if(!visited[nxt[s]]){
		dfs2(nxt[s]);
	}
	tstk.push(s);
}

void dfs3(int s){
	visited[s] = 1;
	
	for(auto v: edges[s]){
		if(!visited[v]){
			dfs3(v);
		}
	}
}

int main(){
	fast;
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>nxt[i];
		indeg[nxt[i]]++;
		if(i != nxt[i]){
			edges[nxt[i]].pb(i);
		}
	}
	
	for(int i = 1; i <= n; i++){
		tocall.insert({indeg[i], i});
	}
	
	int mn = 0, mx = 0;
	
	for(auto x: tocall){
		if(!visited[x.se]){
			dfs1(x.se);
			mn++;
		}
	}
	
	for(int i = 1; i <= n; i++) visited[i] = 0;
	
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs2(i);
		}
	}
	
	for(int i = 1; i <= n; i++) visited[i] = 0;
	
	while(!tstk.empty()){
		if(!visited[tstk.top()]){
			dfs3(tstk.top());
			mx++;
		}
		
		tstk.pop();
	}
	
	
	cout<<mn<<' '<<mx<<'\n';
	
	return 0;
}
