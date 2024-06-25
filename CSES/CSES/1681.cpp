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

vector <vector <ll>> adj(mxn);
ll dp[mxn];

ll dfs(ll src, ll target){
	if(src == target){
		return 1;
	}

	if(dp[src] != -1){
		return dp[src] % mod;
	}

	ll ans = 0;
	for(auto it : adj[src]){
		ans += dfs(it, target);
		ans %= mod;
	}

	return dp[src] = ans % mod;
}

void solve() {
    ll n, m;	
    cin >> n >> m;

    for(ll i = 0; i < m; ++i){
    	ll u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    }

    memset(dp, -1, sizeof(dp));

    cout << dfs(0, n - 1);
}

int main(){
    
    fast();

    solve();

    return 0;
}