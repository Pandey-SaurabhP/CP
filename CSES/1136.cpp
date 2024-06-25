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
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
 
// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
// Constants
const ll mxn = 2e5 + 5;
const ll lgn = 22;
const ll mod = 1e9 + 7;
 
// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
// Solve
 
int up[mxn][lgn];
vector <vector <int>> adj(mxn);
int depth[mxn];

int sum[mxn];
int stop[mxn];
 
void dfs(int root, int par){
	if(root == 0) depth[root] = 1;
 
	for(auto it : adj[root]){
		up[it][0] = root;
		depth[it] = depth[root] + 1;
 
		for(int i = 1; i < lgn; ++i){
			if(up[it][i - 1] != -1) up[it][i] = up[up[it][i - 1]][i - 1];
		}
 
		if(it != par) dfs(it, root);
	}
}
 
int getKth(int node, int k){
 
	for(int i = lgn - 1; i >= 0; --i){
		if(pow(2, i) <= k){
			k -= pow(2, i);
 
			if(node != -1) node = up[node][i];
		}
	}
 
	if(node == -1) return -1;
	return node + 1;
}
 
int getLCA(int a, int b){

	int lo = 0;
	int hi = 200005;
 
	if(depth[a] < depth[b]){
		swap(a, b);
	}
 
	for (int i = lgn - 1; i >= 0; --i) {
        if (depth[a] - depth[b] >= pow(2, i)) {
            if (a != -1) {
                a = up[a][i];
            }
        }
    }
 
    if(a == b) return a + 1;
 
    for(int i = lgn - 1; i >= 0; --i){
    	if(up[a][i] != up[b][i]){
    		a = up[a][i];
    		b = up[b][i];
    	}
    }
 
    if(up[a][0] == -1) return -1;
    return up[a][0] + 1;
}

int aa[mxn];
void dfs2(int root, int par, int sm){

	aa[root] = sm;

	for(auto it : adj[root]){
		if(it != par) dfs2(it, root, sm + sum[root] - stop[root]);
	}
}
 
void solve() {
	memset(up, -1, sizeof(up));
	memset(aa, 0, sizeof(aa));
	memset(sum, 0, sizeof(sum));
	memset(stop, 0, sizeof(stop));
    	
    int n, q;
    cin >> n >> q;
 
    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;
    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }
 
    dfs(0, 0);


    while(q--){
    	int x, y;
    	cin >> x >> y;
    	--x, --y;

    	int lca = getLCA(x, y);

    	cout << x << " " << y << " : " << lca << "\n";

    	sum[lca]++;

    	if(lca != x && lca != y){
	    	stop[x]++;
	    	stop[y]++;
    	}
    	else if(lca == x){
    		stop[y]++;
    	}
    	else{
    		stop[x]++;
    	}
    }

    print(sum, i, n);
    print(stop, i, n);

    dfs2(0, 0, sum[0]);

    for(int i = 0; i < n; ++i){
    	cout << aa[i] << " ";
    }
    cout << "\n";
}
 
int main(){
    
    fast();
    solve();
 
    return 0;
   }
