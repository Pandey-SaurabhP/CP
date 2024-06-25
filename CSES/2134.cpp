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
const ll lgn = 22;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Segment Tree for sum, point update range query
vector <vector <ll>> segTree;
vector <ll> segTreeTmp;
 
void update(ll l, ll r, ll i, ll x, ll v, vector <ll> &sg){
    if(l == r){
        sg[i] = v;
        return;
    }
 
    ll mid = (l + r) / 2;
 
    if(mid >= x) update(l, mid, 2 * i + 1, x, v, sg);
    else update(mid + 1, r, 2 * i + 2, x, v, sg);
    
 
    sg[i] = max(sg[2 * i + 1], sg[2 * i + 2]);
}
 
void build(ll l, ll r, ll i, vector <ll> &a, ll &n, vector <ll> &sg){
    if(l == r){
        sg[i] = a[l];
        return;
    }
 
    ll mid = (l + r) / 2;
 
    build(l, mid, 2 * i + 1, a, n, sg);
    build(mid + 1, r, 2 * i + 2, a, n, sg);
 
    sg[i] = sg[2 * i + 1] + sg[2 * i + 2]; 
}
 
ll query(ll l, ll r, ll i, ll lll, ll rr, vector <ll> &sg){
    if(r < lll || l > rr) return 0;
 
    if(l >= lll && r <= rr){
        return sg[i];
    }
 
    ll mid = (l + r) / 2;
 
    return query(l, mid, 2 * i + 1, lll, rr, sg) + query(mid + 1, r, 2 * i + 2, lll, rr, sg);
}


// HLD + Solve
vector <ll> parent(mxn, -1);
vector <vector <ll>> adj(mxn);
vector <ll> maxDepth(mxn);
vector <vector <ll>> chains(mxn);
vector <ll> chainId(mxn);

vector <ll> Index(mxn, -1);

ll c = 0;

// DFS
ll fillDepth(ll root, ll par){
	ll d = 0;

	for(auto it : adj[root]){
		if(it != par){
			parent[it] = root;
			d = max(fillDepth(it, root), d);
		}
	}

	maxDepth[root] = d;

	return d + 1;
}

set <pii> heavy;

void hld(ll root, ll par = 0){
	ll mx = maxDepth[root];

	// Mark the max depth edge as heavy, rest as light
	bool heavyMarked = 0;

	for(auto it : adj[root]){

		if(it != par){
			if(maxDepth[it] == mx - 1 && !heavyMarked){
				// Mark it as light edge
				heavy.insert({root, it});
				heavyMarked = 1;
			}

			hld(it, root);
		}
	}
}

ll id = 0;

void buildHLD(ll root, ll par = 0){
	chains[id].pb(root);
	chainId[root] = id;
	Index[root] = chains[id].size() - 1;

	ll mxId = -1;

	for(auto it : adj[root]){
		if(it != par){
			if(heavy.count({root, it})){
				mxId = it;
				buildHLD(it, root);
				break;
			}
		}
	}

	for(auto it : adj[root]){
		if(it != par && it != mxId){
			++id;
			buildHLD(it, root);
		}
	}
}

// Binary Lifting
int up[mxn][lgn]; // memset
int depth[mxn];

void buildUp(int root, int par){
 	parent[root] = par;
 
	for(auto it : adj[root]){
		if(it == par) continue;
 		
 
		up[it][0] = root;
 
		for(int i = 1; i < lgn; ++i){
			if(up[it][i - 1] != -1) up[it][i] = up[up[it][i - 1]][i - 1];
		}
 
		buildUp(it, root);
	}
}

int getLCA(int a, int b){

	if(depth[a] < depth[b]){
		swap(a, b);
	}
 
	for (int i = lgn - 1; i >= 0; --i) {
        if (depth[a] - depth[b] >= pow(2, i)) {
            if (a != -1) {
                a = up[a][i];
            }
        }
    }
 
    if(a == b) return a;
 
    for(int i = lgn - 1; i >= 0; --i){
    	if(up[a][i] != up[b][i]){
    		a = up[a][i];
    		b = up[b][i];
    	}
    }
 
    if(up[a][0] == -1) return -1;
    return up[a][0];
}


void solve(){

	ll n, m;
	cin >> n >> m;

	vector <ll> v(n);
	read(v, i, n);

	for(ll i = 0; i < n - 1; ++i){
		ll u, v;
		cin >> u >> v;

		--u, --v;

		adj[u].pb(v);
		adj[v].pb(u);
	}

	fillDepth(0, 0);
	hld(0);
	buildHLD(0, 0);

	for(ll i = 0; chains[i].size() != 0; ++i){

		segTreeTmp.resize(4 * chains[i].size());
		ll sz = chains[i].size();

		vector <ll> values(chains[i].size());

		for(ll j = 0; j < chains[i].size(); ++j){
			values[j] = v[chains[i][j]];
		} 

		build(0, chains[i].size() - 1, 0, values, sz, segTreeTmp);

		segTree.pb(segTreeTmp);
	}

	for(ll i = 0; i < m; ++i){

		ll type;
		cin >> type;

		if(type == 2){
			ll u, v;
			cin >> u >> v;

			--u, --v;

			cout << u << " " << v << " ";

			ll smu = 0;

			while(u != -1){
				ll liesIn = chainId[u];

				smu += query(0, chains[liesIn].size() - 1, 0, 0, Index[u], segTree[liesIn]);
				u = parent[chains[liesIn][0]];
			}

			ll smv = 0;

			while(v != -1){
				ll liesIn = chainId[v];

				smv += query(0, chains[liesIn].size() - 1, 0, 0, Index[v], segTree[liesIn]);
				v = parent[chains[liesIn][0]];
			}

			ll smlca = 0;

			ll lca = getLCA(u, v);

			cout << lca << "\n";

			while(lca != -1){
				ll liesIn = chainId[lca];

				smlca += query(0, chains[liesIn].size() - 1, 0, 0, Index[lca], segTree[liesIn]);
				lca = parent[chains[liesIn][0]];
			}

			// cout << smu + smv - 2 * smlca << " ";
		}
		else{
			ll u, val;
			cin >> u >> val;

			--u;

			ll liesIn = chainId[u];
			ll id = Index[u];

			update(0, chains[liesIn].size() - 1, 0, id, val, segTree[liesIn]);	
		}
	}
}

int main(){
    fast();
    solve();

    return 0;
}