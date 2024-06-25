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

vector <int> ans(200005, -1);
vector <bool> vis(200005, 0);
vector <bool> vis2(200005, 0);
vector <bool> vis3(200005, 0);
vector <int> a(200005, 0);
vector <int> dp(200005 , -1);


int slv(int root, int sz){
		if(dp[root] != -1) return dp[root];

	if(vis[root]){
		return root;
	}


	vis[root] = 1;
	int xyz = slv(a[root], sz + 1);


	return dp[root] = xyz;
}

int getSize(int root, int core){

	if(root == core){
		return 1;
	}

	int xyz = getSize(a[root], core);

	return 1 + xyz;
}

void fill(int root, pii &z){

	if(vis2[root]){
		return;
	}

	vis2[root] = 1;
	ans[root] = z.ss;
	fill(a[root], z);
}

int dfs(int root){

	if(ans[root] != -1){
		return ans[root];
	}

	int cans = dfs(a[root]);

	return ans[root] = cans + 1;
}

void solve() {
    int n;
    cin >> n;

    read(a, i, n);

    for(int i = 0; i < n; ++i) --a[i];

    for(int i = 0; i < n; ++i){
    	if(!vis[i]){
    		int xyz = slv(i, 0);
    		// print(vis, i, n);
    		// cout << "XYZ : " << i << " " << xyz << "\n";
    		int sz = getSize(a[xyz], xyz);

    		pii zxc = {xyz, sz};
    		fill(zxc.ff, zxc);
    	}
    }

    // print(ans, i, n);

    for(int i = 0; i < n; ++i){
    	if(ans[i] == -1){
    		dfs(i);
    	}
    }

    print(ans, i, n);

}

int main(){
    
    // fast();

    solve();

    return 0;
}