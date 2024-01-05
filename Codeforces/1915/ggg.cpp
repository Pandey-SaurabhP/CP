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
typedef pair <int, int> pii;

// Constants
const ll mxn = 1e3 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

vector <vector <pii>> adj(mxn);

ll dist[mxn][mxn];
vector <ll> s(mxn);



int main(){
    // fast();
    

    ll t;
    cin >> t;


    while(t--){

        ll n, m;
        cin >> n >> m;

        for(ll i = 0; i < m; ++i){
            ll u, v, w;
            cin >> u >> v >> w;

            --u, --v;

            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }


        for(int i = 0; i < n; ++i){
            cin >> s[i];
        }

        for(ll i = 0; i < mxn; ++i){
            for(ll j = 0; j < mxn; ++j){
                dist[i][j] = 1e18;
            }
        }

        dist[0][s[0]] = 0;

        priority_queue <pair <pii, ll>, vector <pair <pii, ll>>, greater <pair <pii, ll>>> pq; // Wt Edge , cycle

        pq.push({{0, 0}, s[0]});

        while(!pq.empty()){

            auto tp = pq.top();
            pq.pop();

            ll u = tp.ff.ss;
            ll k = tp.ss;

            for(auto it : adj[u]){
                ll v = it.ff;
                ll w = it.ss;

                ll c = min(k, s[it.ff]);

                if(dist[v][c] > dist[u][k] + w * k){
                    dist[v][c] = dist[u][k] + w * k;

                    pq.push({{dist[v][c], v}, c});
                }
            }
        }

        ll ans = 1e18;

        for(ll i = 0; i < 1001; ++i){
            ans = min(ans, dist[n - 1][i]);
        }

        cout << ans << "\n";

        for(int i = 0; i < mxn; ++i){
            adj[i].clear();
        }
    }

    return 0;
}