#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
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

vector <int> in(mxn, 0), out(mxn, 0);
vector <int> ans;
vector <bool> vis(mxn, 0); 
vector <vector <int>> adj(mxn);

void dfs(int src, int dest){

	while(adj[src].size() > 0){
		int m = adj[src].size();
		int node = adj[src][m - 1];

		--out[src];
		--in[node];

		adj[src].pop_back();

		dfs(node, dest);
	}

	ans.pb(src);

	return;
}

void solve() {
    int n, m;
    cin >> n >> m;

    rep(i, 0, m){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	in[v]++; out[u]++;
    }

    int cnt1 = 0, cnt2 = 0;
    bool ok = 1;

    for(int i = 0; i < n; ++i){
    	if(in[i] != out[i]){
	    	if(in[i] - out[i] == 1){
	    		++cnt1;
	    	}
	    	else if(out[i] - in[i] == 1){
	    		++cnt2;
	    	}
	    	else{
	    		ok = 0;
	    		break;
	    	}
    	}
    }

    if(!ok || cnt1 != 1 || cnt2 != 1){
    	cout << "IMPOSSIBLE\n";
    }
    else{
    	if(out[0] - in[0] == 1 && in[n - 1] - out[n - 1] == 1){

    		// print(out, i, n);
    		dfs(0, n - 1);
    		reverse(ans.begin(), ans.end());
    		if(ans.size() != m + 1){
    			cout << "IMPOSSIBLE\n"; return;
    		}
    		rep(i, 0, ans.size()){
    			cout << ans[i] + 1 << " ";
    		}
    		cout << "\n";
    	}
    	else cout << "IMPOSSIBLE\n";
    }
}

int main(){```
    
    fast();

    solve();

    return 0;
}

// 1 3 4  9
// 6 7 12 13