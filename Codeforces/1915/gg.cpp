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

void solve() {
    for(int i = 0; i < mxn; ++i){
        adj[i].clear();     
    }

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        --u, --v;

        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector <int> s(n);
    read(s, i, n);


    int dist[mxn][mxn];

    for(int i = 0; i < mxn; ++i){
        for(int j = 0; j < mxn; ++j){
            dist[i][j] = INT_MAX;
        }
    }

    priority_queue <pair <pii, int>> pq; // Wt Edge , cycle
    pq.push({{0, 0}, s[0]});

    while(!pq.empty()){

        auto tp = pq.top();
        pq.pop();

        int u = tp.ff.ss;

        for(auto it : adj[u]){
            int v = it.ff;
            int w = it.ss;

            int c = min(tp.ss, s[it.ff]);

            if(dist[v][c] > dist[u][tp.ss] + it.ss * tp.ss){
                dist[v][c] = dist[u][tp.ss] + it.ss * tp.ss;

                pq.push({{dist[v][c], v}, c});
            }
        }
    }

    int ans = INT_MAX;

    for(int i = 0; i < 1001; ++i){
        ans = min(ans, dist[n - 1][i]);
    }

    cout << ans << "\n";
}

int main(){
    
    // fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}