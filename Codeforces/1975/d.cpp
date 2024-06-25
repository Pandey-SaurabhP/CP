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

vector <vector <int>> adj(mxn);
vector <int> depth(mxn);

int getDepth(int root, int par){

	int d = 0;

	for(auto it : adj[root]){
		if(it != par){
			d = max(getDepth(it, root), d);
		}
	}

	return depth[root] = 1 + d;
}

vector <int> path;

bool findPath(int x, int par, int y){

	path.pb(x);

	if(x == y){
		return 1;
	}

	for(auto it : adj[x]){
		if(it != par){
			if(findPath(it, x, y)){
				return 1;
			}
		}
	}

	path.pop_back();

	return 0;
}

set <int> vis;
int steps = 0;

bool dfs(int root, int par, int n){
	
	vis.insert(root);
	if(vis.size() == n){
		return 1;
	}


	for(auto it : adj[root]){
		if(it != par){
			++steps;
			if(dfs(it, root, n)){
				return 1;
			}
			++steps;
		}
	}

	return 0;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; ++i){
    	adj[i].clear();
    	depth[i] = -1;
    }
    vis.clear();
    steps = 0;
    path.clear();

    int a, b;
    cin >> a >> b;

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    findPath(a, a, b);

    int sz = (path.size() - 1) / 2;
    int xyz = path[sz];

    // Number of iteration'


    getDepth(xyz, xyz);

    for(int i = 0; i <= n; ++i){
    	sort(adj[i].begin(), adj[i].end(), [] (int x, int y){
    		return depth[x] < depth[y];
    	});
    }

    // print(depth, i, n + 1);
    // for(int i = 0; i <= n; ++i){
    // 	cout << i << " -> ";
    // 	print(adj[i], j, adj[i].size());
    // }

    int ans = path.size() / 2;

    dfs(xyz, xyz, n);

    // cout << ans << " " << steps << "\n";
    ans += steps;

    cout << ans << "\n";

}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}