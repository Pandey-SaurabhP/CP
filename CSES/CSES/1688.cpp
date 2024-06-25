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

int ans[mxn][lgn];
vector <vector <int>> adj(mxn);
int depth[mxn];

void dfs(int root){
	if(root == 0) depth[root] = 1;

	for(auto it : adj[root]){
		ans[it][0] = root;

		depth[it] = depth[root] + 1;

		for(int i = 1; i < lgn; ++i){
			if(ans[it][i - 1] != -1) ans[it][i] = ans[ans[it][i - 1]][i - 1];
		}

		dfs(it);
	}
}

int getKth(int node, int k){

	for(int i = lgn - 1; i >= 0; --i){
		if(pow(2, i) <= k){
			k -= pow(2, i);

			if(node != -1) node = ans[node][i];
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
                a = ans[a][i];
            }
        }
    }

    if(a == b) return a + 1;

    for(int i = lgn - 1; i >= 0; --i){
    	if(ans[a][i] != ans[b][i]){
    		a = ans[a][i];
    		b = ans[b][i];
    	}
    }

    if(ans[a][0] == -1) return -1;
    return ans[a][0] + 1;
}

void solve() {
	memset(ans, -1, sizeof(ans));
    	
    int n, q;
    cin >> n >> q;

    vector <int> ar(n, -1);
    for(int i = 1; i < n; ++i){
    	cin >> ar[i];
    	--ar[i];

    	adj[ar[i]].pb(i);
    }

    dfs(0);

    while(q--){
    	int x, y;
    	cin >> x >> y;
    	--x, --y;
    	cout << getLCA(x, y) << "\n";
    }
}

int main(){
    
    fast();
    solve();

    return 0;
}