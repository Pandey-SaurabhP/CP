#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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
const ll mxn = 1e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <ll>> adj(mxn);
vector <ll> c(mxn);
vector <ll> asc(mxn);

ll dfs(ll root, ll par){

	ll cval = 0;

	for(auto it : adj[root]){
		if(it != par){
			cval += dfs(it, root);
		}
	}

	return asc[root] = cval + c[root];
}

ll oneAns(ll root, ll par, ll d){
	ll dans = 0;
	for(auto it : adj[root]){
		if(it != par){
			dans += oneAns(it, root, d + 1);
		}
	}

	return dans + (d * c[root]);
}

ll ans[mxn];

void getAns(ll root, ll par){

	if(root != 0){
		// cout << root + 1 << " " << par +1 << " : " << ans[par] << " - " << asc[0] << " + " << asc[par] << " - " << asc[root] << "\n";
		ans[root] = ans[par] - asc[root] + (asc[0] - asc[root]);
	}

	for(auto it : adj[root]){
		if(it != par){
			getAns(it, root);
		}
	}
}

void solve() {
    ll n;
    cin >> n;

    for(ll i = 0; i < n - 1; ++i){
    	ll u, v;
    	cin >> u >> v;

    	--u, --v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    read(c, i, n);

    dfs(0, 0);
    ans[0] = oneAns(0, 0, 0);

    getAns(0, 0);

    // print(asc, i, n);
    // print(ans, i, n);

    ll mn = ans[0];
    for(ll i = 0; i < n; ++i){
    	mn = min(mn, ans[i]);
    }

    cout << mn;
}

int main(){
    
    fast();

    solve();

    return 0;
}