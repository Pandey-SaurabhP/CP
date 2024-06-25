#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector<vector<ll>> adj(mxn); // adjacency list of graph
vector <vector <ll>> newAdj(mxn);

vector<bool> visited(mxn);
vector<ll> tin(mxn), low(mxn);
ll timer;

set <pii> bridges;

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (ll to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]){                // IS_BRIDGE(v, to);
            	bridges.insert({v, to});
            	bridges.insert({to, v});
            }
        }
    }
}

void find_bridges(ll n) {
    timer = 0;
    visited.assign(n, 0);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

ll cnt = 0;
void dfs2(ll root, vector <bool> &v){

	v[root] = 1;
	++cnt;
	for(auto it : newAdj[root]){
		if(!v[it]){
			dfs2(it, v);
		}
	}
}

void solve() {
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i <= n; ++i){
    	adj[i].clear();
    	newAdj[i].clear();
    }
    bridges.clear();

    for(ll i = 0; i < m; ++i){
    	ll u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    find_bridges(n);

    // for(auto it : bridges){
    // 	cout << it.ff << " " << it.ss << "\n";
    // }

    for(ll i = 0; i < n; ++i){
    	for(ll j = 0; j < adj[i].size(); ++j){
    		if(!bridges.count({i, adj[i][j]})){
    			newAdj[i].pb(adj[i][j]);
    		}
    	}
    }

    vector <bool> v(n, 0);
    vector <int> sz;

    for(ll i = 0; i < n; ++i){
    	if(!v[i]){
    		cnt = 0;
    		dfs2(i, v);
    		sz.pb(cnt);
    	}
    }


    sort(sz.begin, sz.end());

    int mx, other;
    if(sz.size() == 0){
    	mx = sz.size();
    	other = 0;
    }

    ll ans = (mx * (mx - 1)) / 2;
    ans += (other * (other - 1)) / 2;

    cout << ans << "\n";
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