#include <bits/stdc++.h>
using namespace std;
 
// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()
 
// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
 
// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;
ll inf = 1e18;
 
// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
// Solve
 
void prllPQ(priority_queue <pair <ll, pii>, vector <pair <ll, pii>>, greater <pair <ll, pii>>> pq){
 
    cout << "\n";
 
    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();
 
        cout << tp.ff << " " << tp.ss.ff << " " << tp.ss.ss << "\n";
    }
 
    cout << "\n";
}
 
void solve() {
    ll n, m;
    cin >> n >> m;
 
    vector <vector <pii>> adj(n + 1);
 
    for(ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;
 
        --u; --v;
 
        adj[u].push_back({v, w});
    }
 
    // Djikstra
 
    priority_queue <pair <ll, pii>, vector <pair <ll, pii>>, greater <pair <ll, pii>>> pq;
    // Wt, {edge, hua ki nahi}
    pq.push({0, {0, 0}});
 
    vector <vector <ll>> dist(mxn, vector <ll> (2, inf));
    dist[0][0] = dist[0][1] = 0;
 
    while(!pq.empty()){
        // prllPQ(pq);
 
        auto tp = pq.top();
        pq.pop();
 
        ll w = tp.ff;
        ll u = tp.ss.ff;
        ll used = tp.ss.ss;
 
        if(w > dist[u][used]){
            continue;
        }
 
        for(auto it : adj[u]){
            if(used){
                if(dist[it.ff][1] > w + it.ss){
                    dist[it.ff][1] = w + it.ss;
                    pq.push({dist[it.ff][1], {it.ff, 1}});
                }
            }
            else{
                if(dist[it.ff][0] > w + it.ss){
                    dist[it.ff][0] = w + it.ss;
                    pq.push({dist[it.ff][0], {it.ff, 0}});
                }
 
                if(dist[it.ff][1] > w + it.ss / 2){
                    dist[it.ff][1] = w + it.ss / 2;
                    pq.push({dist[it.ff][1], {it.ff, 1}});
                }
            }
        }
    }
 
    cout << min(dist[n - 1][1], dist[n - 1][0]);
}
 
int main(){
    
    fast();
 
    solve();    
 
    return 0;
}