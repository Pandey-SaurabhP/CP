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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <int> par(mxn, -1);

int isCycle(int root, int par, int core){
	
	vis[root] = 1;

	for(auto it : adj[root]){
		if(!vis[it] && it != par){
			if(isCycle(it, root, core)){
				return 1;
			}
		}
		else if(it != par){
			return wt[{it, par}];
		}
	}

	return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector <int, pii> vc;

    for(int i = 0; i < m; ++i){
    	int u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;

    	vc.pb({w, {u, v}});

    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }

    sort(vc.begin(), vc.end());

    int mn = INT_MAX;

    for(int i = 0; i < m; ++i){
    	
    	int u = vc[i].ss.ff;
    	int v = vc[i].ss.ss;
    	int w = vc[i].ff;

    	if(!vis[u]){

    		vis[u] = 1;

    		if(isCycle(v, u, u)){
    			mn = w;
    			break;
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