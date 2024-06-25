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
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; ++i){
    	ll u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;

    	adj[u].pb({v, w});
    }

    priority_queue <pii, vector <pii>, greater <pii>> pq;

    vector <ll> dist(n, 1000000000000000ll);
    vector <ll> mnd(n, 0);
    vector <ll> mxd(n, 0);
    vector <ll> ways(n, 0);

    mnd[0] = 0;
    mxd[0] = 0;
    dist[0] = 0;
    ways[0] = 1;

    pq.push({0, 0});

    while(!pq.empty()){
    	pii tp = pq.top();
    	pq.pop();

    	ll d = tp.ff;
    	ll u = tp.ss;

    	for(auto it : adj[u]){
    		ll v = it.ff;
    		ll w = it.ss;

    		if(dist[v] > d + w){
    			dist[v] = d + w;
    			mnd[v] = mnd[u] + 1;
    			mxd[v] = mxd[u] + 1;
    			ways[v] = ways[u];

    			pq.push({dist[v], v});
    		}
    		else if(dist[v] == d + w){
    			dist[v] = d + w;
    			ways[v] += ways[u];
    			ways[v] %= mod;
    			mnd[v] = min(mnd[u] + 1, mnd[v]);
    			mxd[v] = max(mxd[u] + 1, mxd[v]);
    		}
    	}
    }

    cout << dist[n - 1] << " " << ways[n - 1] << " " << mnd[n - 1] << " " << mxd[n - 1] << "\n";
}

int main(){
    
    fast();
    solve();

    return 0;
}