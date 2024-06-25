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

vector <vector <int>> adj(mxn);

int comps = 0;
int req = 0;

int dfs(int root, int par, int x){

	int ans = 1;

	for(auto it : adj[root]){
		if(it != par){
			ans += dfs(it, root, x);
		}
	}

	if(comps >= req || ans < x){
		return ans;
	}
	else{
		++comps;
		return 0;
	}
}

void solve() {
    int n, k;
    cin >> n >> k;

    req = k;

    for(int i = 0; i < n; ++i){
    	adj[i].clear();
    }

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    int lo = 1;
    int hi = n - 1;
    int ans = 1;

    while(lo <= hi){

    	int mid = (lo + hi) / 2;

    	comps = 0;

    	int aa = dfs(0, 0, mid);

    	if(aa >= mid){
    		++comps;
    	}

    	if((aa != 0 && aa < mid) || comps <= k){
    		hi = mid - 1;
    	}
    	else{
    		lo = mid + 1;
    		ans = mid;
    	}
    }

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