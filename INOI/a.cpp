#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
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

void solve() {
    ll c, f;
    cin >> c >> f;

    ll dist[c + 1][c + 1];
    
    for(int i = 0; i < c + 1; ++i){
    	for(int j = 0; j < c + 1; ++j){
    		dist[i][j] = INT_MAX;
    	}
    }

    ll u, v, w;

    for(ll i = 0; i < f; ++i){
    	cin >> u >> v >> w;

    	--u, --v;

    	dist[u][v] = w;
    	dist[v][u] = w;
    }

    for(ll k = 0; k < c; ++k){
    	for(ll i = 0; i < c; ++i){
    		for(ll j = 0; j < c; ++j){

    			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    		}
    	}
    }

    ll ans = dist[0][1];

    for(ll i = 0; i < c; ++i){
    	for(ll j = 0; j < c; ++j){
    		if(i != j) ans = max(ans, dist[i][j]);
    	}
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();


    return 0;
}