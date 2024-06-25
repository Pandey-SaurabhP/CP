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
const ll mxn = 301 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
int vis[mxn];
vector <int> adj[mxn];

void dfs(int root){
	vis[root] = 1;

	for(auto it : adj[root]){
		if(!vis[it]){
			dfs(it);
		}
	}
}

void solve() {
	memset(vis, 0, sizeof(vis));
    int n, k;
    cin >> n >> k;

    int a[n][1001];

    for(int i = 0; i < n; ++i){
    	cin >> a[i][0];

    	for(int j = 1; j <= a[i][0]; ++j){
    		cin >> a[i][j];
    	}

    	sort(a[i] + 1, a[i] + a[i][0] + 1);
    }

    for(int i = 0; i < n; ++i){
    	for(int j = i + 1; j < n; ++j){

    		int cmn = 0;
    		for(int l = 1; l <= a[i][0]; ++l){
    			if(binary_search(a[j] + 1, a[j] + a[j][0] + 1, a[i][l])) ++cmn;
    		}

    		if(cmn >= k){
    			adj[i].pb(j);
    			adj[j].pb(i);
    		}
    	}
    }

    dfs(0);

    int ans = accumulate(vis, vis + n, 0);
    cout << ans;
}

int main(){
    
    fast();

    solve();

    return 0;
}