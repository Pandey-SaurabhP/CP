#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

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
vector<pii> adj[mxn + 10];

int n, a, b;

int vala[mxn + 10];
int valb[mxn + 10];

void dfs(int u, int val, int p){
    vala[u] = val;
    for (auto v: adj[u]){
        if (v.first == p) continue;
        if (v.first == b) continue;
        dfs(v.first, val ^ v.second, u);
    }
}
 
void dfs2(int u, int val, int p){
    valb[u] = val;
    for (auto v: adj[u]){
        if (v.first == p) continue;
        dfs2(v.first, val ^ v.second, u);
    }
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
    	adj[i].clear();
    }

    for (int i = 1; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for (int i = 1; i <= n; i++){
        vala[i] = -1;
    }
    for (int i = 1; i <= n; i++){
        valb[i] = 0;
    }

    dfs(a, 0, -1);
    dfs2(b, 0, -1);

    if (vala[b] == 0){
        cout << "YES\n";
    }
    else{
        set<int> st;
        for (int i = 1; i <= n; i++){
            if (vala[i] != -1){
                st.insert(vala[i]);
            }
        }

        bool ok = 0;
        for (int i = 1; i <= n; i++){
            if (i != b){
                if (st.find(valb[i]) != st.end()){
                    ok = 1;
                    break;
                }
            }
        }

        if (ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
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