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
const ll mxn = 2e5 + 5;
const ll mod = 1e9 + 7;
const ll lgn = 30;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve


int depth[mxn];
int up[mxn][lgn];
int par[mxn];
vector <vector <int>> adj(mxn);

void getkth(int root, int k){
	for(int i = 0; i < lgn; ++i){
		if((1 << i) & k){
			root = up[root][i];
		}
	}

	return root;
}


void buildDepth(int root, int d){

	depth[root] = d;
	vis[root] = 1;

	for(auto it : adj[root]){
		if(!vis[root]) buildDepth(it, d + 1);
	}

	return;
}

void build(int n){

	for(int i = 0; i < n; ++i){
		up[i][0] = par[i];
		for(int j = 1; j < lgn; ++j){
			up[i][j] = up[up[i][j - 1]][j - 1];
		}
	}
}

void solve() {

    memset(depth, -1, sizeof(depth));

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; ++i){
    	cin >> par[i];
    	par[i]--;
    	adj[par[i]].pb(i);
    }

    build(n);

    for(int i = 0; i < n; ++i){
    	if(!vis[i]){
    		buildDepth(i, 1);
    	}
    }

    while(q--){
    	int a, b;
    	cin >> a >> b;

    	--a, --b;

    	int da = depth[a];
    	int db = depth[b];

    	if(depth[a] > depth[b]){
    		a = getkth(a, depth[a] - depth[b]);
    	}
    	else{
    		b = getkth(b, depth[b] - depth[a]);
    	}

    	if(a != b){
    		cout << -1 << "\n";
    	}
    	else{
    		cout << 
    	}
    }
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