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
const ll mxn = 501;
const ll mod = 1e9 + 7;

const ll inf = 1e18;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <int>> adj(mxn);
ll r[mxn][mxn];
ll f[mxn][mxn];
ll par[mxn];

bool bfs(ll src, ll dest, ll n){

	queue <ll> q;
	q.push(src);
	par[src] = -1;
	vector <bool> vis(mxn, 0);
	vis[src] = 1;

	while(!q.empty()){
		ll u = q.front();
		q.pop();

		for(auto v : adj[u]){
			if(!vis[v] && r[u][v] > 0){
				vis[v] = 1;
				par[v] = u;
				q.push(v);

				if(v == dest){
					return 1;
				}
			}
		}
	}

	return 0;
}

ll ff(ll src, ll dest, ll n){

	ll ans = 0ll;

	while(bfs(src, dest, n)){
		ll cflow = inf;

		for(ll u = dest; u != src; u = par[u]){
			cflow = min(cflow, r[par[u]][u]);
		}

		for(ll u = dest; u != src; u = par[u]){
			r[par[u]][u] -= cflow;
			r[u][par[u]] += cflow;

			f[par[u]][u] += cflow;
			f[u][par[u]] -= cflow;
		}

		ans += cflow;
	}

	return ans;
}

vector <int> path;

void dfs(int root, int dest){

	if(root == dest){
		cout << path.size() << "\n";
		for(auto it : path){
			cout << it << " ";
		}
		cout << "\n";
		return;
	}


	for(auto it : adj[root]){
		if(f[root][it] > 0){
			path.pb(int(it) + 1);
			f[root][it] = 0;
			dfs(it, dest);
			return;
		}
	}

}

void solve() {

	memset(r, 0, sizeof(r));
	memset(f, 0, sizeof(f));

	ll n, m;
	cin >> n >> m;

	for(ll i = 0; i < m; ++i){
		ll u, v;
		cin >> u >> v;

		--u, --v;

		adj[u].pb(v);
		adj[v].pb(u);
		
		r[u][v] = 1;

	}  

	cout << ff(0, n - 1, n) << "\n";

	for(auto it : adj[0]){
		if(f[0][it] > 0){
			path.clear();

			f[0][it] = 0;
			path.pb(1);
			path.pb(it + 1);

			dfs(it, n - 1);
		}
	}
}

int main(){
    
    fast();

    solve();

    return 0;
}