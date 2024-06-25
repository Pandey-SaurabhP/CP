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

stack <int> st;
vector <vector <int>> adj(mxn);
vector <vector <int>> dp(mxn, {-1, -1, -1});
vector <int> par(mxn, -1);

vector <int> dfs(int src, int target){

	if(src == target){
		return {1, -1, 1};
	}

	if(dp[src][2] != -1){
		return dp[src];
	}

	int fnd = 0;
	int nc = -1;
	int dist = -1;

	for(auto it : adj[src]){

		vector <int> tp = dfs(it, target);

		if(tp[2] == 1){

			fnd = 1;

			if(1 + tp[0] > dist){
				dist = 1 + tp[0];
				nc = it;
			}
		}
	}

	return dp[src] = {1 + dist, nc, fnd};
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
    	par[i] = i;
    }

    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    }

    vector <int> ans = dfs(0, n - 1);

    // cout << "Hello1!\n";

    if(ans[2] == 0){
    	cout << "IMPOSSIBLE\n";
    }
    else{
    	int start = 0;

    	vector <int> ans;

    	while(start != n - 1){
    		// cout << start  + 1 << " ";
    		ans.pb(start + 1);
    		start = dp[start][1];
    	}

    	ans.pb(n);

    	cout << ans.size() << "\n";
    	print(ans, i, ans.size());
    }
}

int main(){
    
    // fast();

    solve();

    return 0;
}