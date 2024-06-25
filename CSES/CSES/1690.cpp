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
const ll mxn = 2e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <ll>> adj(mxn);
ll n, m;
ll dp[20][(1 << 20)];
ll match;

ll slv(ll root, ll bits){
	if(root == n - 1){
        return (bits == match);
    }

    if(dp[root][bits] != -1){
        return dp[root][bits];
    }

    ll x;
    ll ans = 0ll;

	for(auto it : adj[root]){
        x = (1ll << it);
		if((bits | x) != bits){
			ans += slv(it, bits | x);
            ans %= mod;
		}
	}

    return dp[root][bits] = ans % mod;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    match = (1ll << n) - 1;

    for(ll i = 0; i < m; ++i){
    	ll u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    }


    cout << slv(0, 1);

}

int main(){
    
    fast();

    solve();

    return 0;
}