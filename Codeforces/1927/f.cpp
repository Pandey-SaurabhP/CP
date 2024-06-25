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

bool vis[mxn];

vector <vector <int>> adj(mxn);

int par[mxn];
int sz[mxn];
 
int getParent(int x){
    if(x == par[x]){
        return x;
    }
 
    return par[x]  = getParent(par[x]);
}
 
bool unite(int x, int y){
    int px = getParent(x);
    int py = getParent(y);
    
    if(px == py) return 0;
    if(px != py){
        if(sz[px] >= sz[py]){
            par[py] = px;
            sz[px] += sz[py];
        }
        else{
            par[px] = py;
            sz[py] += sz[px];
        }
    }
    return 1;
}

vector <int> vc;

bool dfs(int x, int last, int target){

    vis[x] = 1;
    vc.pb(x);

    if(x == target){
        return 1;
    }


    for(auto it : adj[x]){
        
        if(!vis[it]){

            if(last == x){
                if(it != target && dfs(it, x, target)){
                    return 1;
                }
            }
            else{
                if(dfs(it, x, target)){
                    return 1;
                }
            }
        }
    }

    vc.pop_back();
    return 0;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vc.clear();

    for(int i = 0; i < n; ++i){
        par[i] = i;
        vis[i] = 0;
        sz[i] = 1;
        adj[i].clear();
    }

    vector <pair <int, pii>> edges(m);

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        --u, --v;

        edges[i] = {w, {u, v}};
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    // Sorted in decreasing order

    int ans = INT_MAX;
    int x, y;
    x = y = -1;

    for(int i = 0; i < m; ++i){
        int u = edges[i].ss.ff;
        int v = edges[i].ss.ss;
        int w = edges[i].ff;

        if(!unite(u, v)){
            // Part of same component, and part of cycle
            ans = w;
            x = u;
            y = v;
        }
        else{
            // Unite this part
            // Already united in above call
            // So do nothing
        }
    }

    // We have found the minimum, traverse a path from x to y
    // cout << x << " " << y << "\n";
    dfs(x, x, y);

    cout << ans << " " << vc.size() << "\n";
    for(auto it : vc){
        cout << it + 1 << " ";
    }
    cout << "\n";
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