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
    else{
        update(mid + 1, r, 2 * i + 2, x, v, sg);
    }
 
    sg[i] = sg[2 * i + 1] + sg[2 * i + 2];
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


// Solve
vector <vector <ll>> adj(mxn);
vector <ll> maxDepth(mxn);
vector <vector <ll>> chains(mxn);
vector <ll> chainId(mxn);
vector <ll> up(mxn, -1);
vector <ll> pos(mxn, -1);
vector <ll> Index(mxn, -1);

ll c = 0;

// DFS
ll fillDepth(ll root, ll par){
	ll d = 0;

	for(auto it : adj[root]){
		if(it != par){
			up[it] = root;
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

	// cout << "Completed Input\n";

	fillDepth(0, 0);
	hld(0);
	buildHLD(0, 0);

	// cout << "Heavy :\n";
	// for(auto it : heavy){
	// 	cout << it.ff << " " << it.ss << "\n"; 
	// }
	// cout << "\n";

	// for(ll i = 0; chains[i].size() != 0; ++i){
	// 	cout << i << " : ";
	// 	print(chains[i], j, chains[i].size());
	// }

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
			ll u;
			cin >> u;

			--u;

			ll sm = 0;

			// cout << "[u], " << u << " : ";

			while(u != -1){
				// cout << u << " lies in ";
				ll liesIn = chainId[u];
				// cout << liesIn << "\n";

				sm += query(0, chains[liesIn].size() - 1, 0, 0, Index[u], segTree[liesIn]);
				u = up[chains[liesIn][0]];
				// cout << u << "\n";
			}

			cout << sm << "\n";
		}
		else{
			ll u, val;
			cin >> u >> val;

			--u;

			ll liesIn = chainId[u];
			ll id = Index[u];

			// cout << liesIn << " " << id << "\n";
			// print(segTree[liesIn], i, segTree[liesIn].size());

			update(0, chains[liesIn].size() - 1, 0, id, val, segTree[liesIn]);	
		}
	}
}

int main(){
    fast();
    solve();

    return 0;
}