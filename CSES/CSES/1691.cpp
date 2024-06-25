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
const ll mxn = 1e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <set <int>> adj(mxn);
vector <int> in(mxn), out(mxn);
vector <int> path;

void dfs(int root){
	while(adj[root].size()){
		int m = adj[root].size();
		int it = *adj[root].begin();

		adj[root].erase(it);
		adj[it].erase(root);
		dfs(it);
	}

	path.pb(root);
}

void solve() {
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v;
    	--u, --v;

    	adj[u].insert(v);
    	adj[v].insert(u);

    	in[u]++, in[v]++, out[u]++, out[v]++;
    }

    // print(in, i, n);
    // print(out, i, n);

    bool ok = 1;

    for(int i = 0; i < n; ++i){
    	if(in[i] != out[i]){
    		ok = 0; break;
    	}
    	if(in[i] % 2 == 1){
    		ok = 0; break;
    	}
    }

    if(!ok) cout << "IMPOSSIBLE\n";
    else{
    	dfs(0);

    	// print(path, i, path.size());

    	if(path.size() == m + 1){
    		reverse(path.begin(), path.end());
    		rep(i, 0, path.size()){
    			cout << path[i] + 1 << " ";
    		}
    		cout << "\n";
    	}
    	else{
    		cout << "IMPOSSIBLE\n";
    	}
    }
}

int main(){
    
    // fast();
    solve();

    return 0;
}