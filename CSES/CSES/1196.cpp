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

vector <vector <pii>> adj(mxn);

void solve() {
    
    ll n, m, k;
    cin >> n >> m >> k;

    for(ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;

        --u, --v;

        adj[u].pb({v, w});
    }

    priority_queue <pii, vector <pii>, greater <pii>> pq;
    pq.push({0, 0});

    ll dist[n][k + 1];

    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j <= k; ++j){
            dist[i][j] = 1000000000000000000ll;
        }
    }

    while(!pq.empty()){
        pii tp = pq.top();
        pq.pop();

        ll u = tp.ss;
        ll d = tp.ff;

        if(dist[u][k - 1] < d) continue;

        for(auto it : adj[u]){
            ll v = it.ff;
            ll w = it.ss;

            if(d + w < dist[v][k - 1]){
                dist[v][k - 1] = d + w;
                pq.push({dist[v][k - 1], v});
                sort(dist[v], dist[v] + k);
            }
        }
    }


    for(ll i = 0; i < k; ++i){
        cout << dist[n - 1][i] << " ";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}