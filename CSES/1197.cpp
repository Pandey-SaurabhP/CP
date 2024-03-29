#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 3e3 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <pii>> adj(mxn);
vector <pair <int, pii>> edge;
vector <int> comps;
vector <bool> vis(mxn, 0);
vector <int> dist(mxn, inf);

void dfs(int root){

	vis[root] = 1;

	for(auto it : adj[root]){
		if(!vis[it.ff]){
			dfs(it.ff);
		}
	}
}

void solve() {
    int n, m;
    cin >> n >> m;



    for(int i = 0; i < m; ++i){
    	int u, v, w;
    	cin >> u >> v >> w;

    	--u;
    	--v;

    	adj[u].pb({v, w});
    	edge.pb({w, {u, v}});
    }

    for(int i = 0; i < n; ++i){
    	if(!vis[i]){
    		comps.pb(i);
    		dfs(i);
    	}
    }

    for(auto it : comps){
    	dist[it] = 0;
    }

    vector <int> parent(mxn);
    for(int i = 0; i < mxn; ++i){
    	parent[i] = i;
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){

    		int u = edge[j].ss.ff;
    		int v = edge[j].ss.ss;
    		int w = edge[j].ff;

    		if(dist[u] != INT_MAX){
				dist[v] = min(dist[u] + w, dist[v]);	
    		}
    	}
    }

    vector <int> dist2 = dist;

    bool changed = 0;

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){

    		int u = edge[j].ss.ff;
    		int v = edge[j].ss.ss;
    		int w = edge[j].ff;

    		if(dist2[u] != INT_MAX){
    			changed = 1;
				dist2[v] = min(dist2[u] + w, dist2[v]);	
    		}
    	}
    }

}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}