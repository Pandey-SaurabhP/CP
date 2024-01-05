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
const ll mxn = 1e3 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
vector <vector <pii>> adj(mxn);
vector <ll> s(mxn);

ll n, m;
ll dp[mxn][mxn];
bool vis[mxn][mxn];

ll dfs(ll root, ll lastSel){

	if(root == n - 1){
		return 0;
	}

	if(dp[root][lastSel] != -1){
		return dp[root][lastSel];
	}

	ll ans = INT_MAX;

	for(auto it : adj[root]){

		int v = it.ff;
		int w = it.ss;

		ans = min(ans, (s[lastSel] * w) + dfs(v, lastSel));
		ans = min(ans, (s[root] * w) + dfs(v, root));
	}

 
	return dp[root][lastSel] = ans;
}


void solve() {
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));


    cin >> n >> m;

    for(ll i = 0; i <= n; ++i){
    	adj[i].clear();
    }

    for(ll i = 0; i < m; ++i){
    	ll u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;

    	adj[u].pb({v, w});
    	adj[v].pb({u, w});
    }

    
    read(s, i, n);

    cout << dfs(0, 0) << "\n";   
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