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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <ll>> adj(mxn);
vector <ll> cnt(mxn);

ll final[mxn];

ll buildPre(ll root, ll par){
	ll res = 0;

	for(auto it : adj[root]){
		if(it != par){
			res += buildPre(it, root);
		}
	}

	return cnt[root] = 1 + res;
}

ll initial(ll root, ll par, ll dist){
	ll res = dist;

	for(auto it : adj[root]){
		if(it != par){
			res += initial(it, root, dist + 1);
		}
	}

	return res;
}

int tot;

void dfs(ll root, ll par, ll ans){
	final[root] = ans;

	for(auto it : adj[root]){
		if(it != par){
			dfs(it, root, ans + tot - 2 * cnt[it]);
		}
	}

}

void solve() {
	memset(final, 0, sizeof(final));

    ll n;
    cin >> n;

    tot = n;
 
    for(ll i = 0; i < n - 1; ++i){
    	ll u, v;
    	cin >> u >> v;
 
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    buildPre(1, 1);

    dfs(1, 1, initial(1, 0, 0));

    for(ll i = 1; i <= n; ++i){
    	cout << final[i] << " ";
    }
}

int main(){
    
    fast();
    solve();

    return 0;
}