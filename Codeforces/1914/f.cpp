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
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
vector <vector <int>> adj(mxn);
vector <int> sz(mxn);

int dfs2(int root){

	int cnt = 1;

	for(auto it : adj[root]){
		cnt += dfs2(it);
	}

	return sz[root] = cnt;
}

int dfs(int root, int k){
	
	int tot = 0;
	int mx = 0;

	for(auto it : adj[root]){
		tot += sz[it];
		mx = max(mx, sz[it]);
	}

	if(tot == 0) return 0;

	if(mx - k <= tot - mx){
		if(tot % 2 == 1){
			if(k == 0){
				return 1;
			}
			else{
				return 0;
			}
		}

		return max(1 - k, 0);
	}
	else{
		int ans = INT_MAX;

		for(auto it : adj[root]){
			if(sz[it] == mx){
				ans = min(ans, 1 + dfs(it, tot - mx));
			}
		}

		return max(ans - k, 0);
	}
}

void solve() {
    int n;
    cin >> n;


    for(int i = 0; i <= n; ++i){
    	adj[i].clear();
    }

    vector <int> p(n - 1);
    read(p, i, n - 1);

    for(int i = 0; i < n - 1; ++i){
    	adj[p[i]].pb(i + 2);
    }

    dfs2(1);

    int xyz = dfs(1, 0);

    xyz = (n - xyz) / 2;

    cout << xyz << "\n";
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