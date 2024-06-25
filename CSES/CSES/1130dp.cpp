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

vector <vector <int>> adj(mxn);
int dp[mxn][2];

void slv(int root, int par){


	for(auto it : adj[root]){
		if(it != par){
			slv(it, root);
			dp[root][0] += max(dp[it][0], dp[it][1]);
		}
	}

	for(auto it : adj[root]){
		if(it != par){
			dp[root][1] = max(dp[root][1],
							  dp[it][0] + dp[root][0] + 1 - 
							  max(dp[it][0], dp[it][1]));
		}
	}

	return;
}

void solve() {
	memset(dp, 0, sizeof(dp));

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    slv(0, 0);

    cout << max(dp[0][1], dp[0][0]);
}

int main(){
    
    fast();

    solve();

    return 0;
}