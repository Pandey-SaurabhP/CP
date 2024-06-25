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
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] + 1 << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 2e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <int>> adj(mxn);
vector <bool> vis(mxn, 0);

vector <int> cur;

bool isCycle(int root, int last, int core){

    cur.pb(root);

    vis[root] = 1;

    if(root == core){
        return 1;
    }

    for(auto it : adj[root]){
        if(!vis[it]){
            if(isCycle(it, root, core)){
                return 1;
            }
        }
    }

    cur.pop_back();

    return 0;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; ++i){
        adj[i].clear();
        vis[i] = 0;
    }

    cur.clear();

    vector <pair <int, pii>> edge(m);

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        --u, --v;

        edge[i] = {w, {u, v}};
        adj[u].pb(v);
        adj[v].pb(u);
    }

    sort(edge.begin(), edge.end());

    int mn = INT_MAX;

    for(int i = 0; i < m; ++i){
        if(!vis[edge[i].ss.ff]){

            vis[edge[i].ss.ff] = 1;
            cur.pb(edge[i].ss.ff);

            if(isCycle(edge[i].ss.ss, edge[i].ss.ff, edge[i].ss.ff)){
                
                mn = edge[i].ff;
                break;
            }
            cur.pop_back();
        }
    }

    set <int> st;
    vector <int> vc;

    for(int i = cur.size() - 1; i >= 0; --i){
        if(st.count(cur[i])){
            break;
        }

        st.insert(cur[i]);
        vc.pb(cur[i]);
    }

    reverse(vc.begin(), vc.end());
    cout << mn << " " << vc.size() << "\n";
    print(vc, i, vc.size());
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