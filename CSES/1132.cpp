#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";}

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 2e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <int>> adj(mxn);
vector <vector <int>> maxDepth(mxn); // of children of ith node
vector <int> par(mxn);
vector <int> ans(mxn);

int dfs1(int root, int parent){

	int mx = 0;

	for(auto it : adj[root]){
		if(it != parent){
			int val = dfs1(it, root);

			maxDepth[root].pb(val);
			mx = max(mx, val);
		}
	}

	par[root] = parent;
	return 1 + mx;
}

int getAns(int root, int cd){

	ans[root] = 0;

	if(maxDepth[root].size() > 0){
		if(maxDepth[root][0] != cd) ans[root] = maxDepth[root][0];
		else if(maxDepth[root].size() > 1){
			ans[root] = maxDepth[root][1];	
		}
	}

	if(root != 0){
		ans[root] = max(ans[root], getAns(par[root], cd + 1));
	}
}

void dfs2(int root, int parent){

	for(auto it : adj[root]){
		if(it != parent){
			dfs2(it, root);
		}
	}

	ans[root] = 0;
	if(maxDepth[root].size() != 0){
		ans[root] = maxDepth[root][0];
	}

	int tmp = par[root];
	int cd = 1;

	while(tmp != 0){
		ans[root] = (cd != maxDepth[tmp][0]? maxDepth[tmp][0]: (maxDepth[tmp].size() >= 2? maxDepth[tmp][1]: ans[root]));
		++cd; tmp = par[root];
	}
}

void solve() {
    
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u; --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    dfs1(0, 0);

    for(int i = 0; i < n; ++i){
    	sort(maxDepth[i].rbegin(), maxDepth[i].rend());
    }

    dfs2(0, 0);

    for(int i = 0; i < n; ++i){
    	cout << i + 1 << " : ";
    	print(maxDepth[i], j, maxDepth[i].size());
    	cout << " : " << ans[i] << "\n";
    }
}

int main(){
    
    fast();

    solve();
    

    return 0;
}