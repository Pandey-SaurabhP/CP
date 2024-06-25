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

ll par[mxn];
ll sz[mxn];
 
ll getParent(ll x){
    if(x == par[x]){
        return x;
    }
 
    return par[x]  = getParent(par[x]);
}
 
void unite(ll x, ll y){
    ll px = getParent(x);
    ll py = getParent(y);
 
    if(px != py){
        if(sz[px] >= sz[py]){
            par[py] = px;
            sz[px] += sz[py];
        }
        else{
            par[px] = py;
            sz[py] += sz[px];
        }
    }
}
 
bool find(ll x, ll y){
    ll px = getParent(x);
    ll py = getParent(y);
 
    return px == py;
}

bool vis[mxn];

void twoPlus(ll root){
	vis[root] = 1;

	for(auto it : adj[root]){
		if(!vis[it]){
			twoPlus(it);
		}
	}
}

vector <pair <ll, pii>> edge;

void solve() {
	for(ll i = 0; i < mxn; ++i){
		par[i] = i;
		sz[i] = 1;
		vis[i] = 0;
	}

 	ll n, m;
 	cin >> n >> m;

 	for(ll i = 0; i < m; ++i){
 		ll u, v, w;
 		cin >> u >> v >> w;

 		adj[u].pb(v);
 		adj[v].pb(u);

 		edge.pb({w, {u, v}});
 	}   

 	twoPlus(1);
 	bool ok = 1;

 	for(ll i = 1; i <= n; ++i){
 		if(!vis[i]){
 			ok = 0;
 			break;
 		}
 	}

 	if(!ok){
 		cout << "IMPOSSIBLE\n";
 		return;
 	}

 	sort(edge.begin(), edge.end());

 	ll cst = 0;

 	for(ll i = 0; i < m; ++i){

 		ll u = edge[i].ss.ff;
 		ll v = edge[i].ss.ss;
 		ll w = edge[i].ff;

 		if(!find(u, v)){
 			cst += w;
 			unite(u, v);
 		}
 	}

 	cout << cst << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}