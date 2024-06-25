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
const ll lgn = 22;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

vector <vector <ll>> chainsSGT(mxn);

// Iterative Segment Tree Basic Only
void build(vector <ll> &a, ll n, ll id){
	for(ll i = 0; i < n; ++i){
		chainsSGT[id][i + n] = a[i];
	}

	for(ll i = n - 1; i >= 1; --i){
		chainsSGT[id][i] = max(chainsSGT[id][2 * i], chainsSGT[id][2 * i + 1]);
	}

	// print(chainsSGT[id], i, 2 * n);
}

void update(ll pos, ll val, ll n, ll id){
	pos += n;
	chainsSGT[id][pos] = val;

	while(pos > 1){
		pos >>= 1;
		chainsSGT[id][pos] = max(chainsSGT[id][2 * pos], chainsSGT[id][2 * pos + 1]);
	}
}

ll query(ll l, ll r, ll n, ll id){
	ll res = INT_MIN;

	l += n;
	r += n;

	while(l < r){

		// cout << l << " " << r << " : " << res << "\n";
		if(l & 1){
			res = max(res, chainsSGT[id][l++]);
		}

		if(r & 1){
			res = max(res, chainsSGT[id][--r]);
		}

		l >>= 1;
		r >>= 1;
	}



	return res;
}
// End of Segment Tree


// End

// Basics
vector <vector <ll>> adj(mxn);
vector <ll> childCnt(mxn);


// Binary Lifting
ll up[mxn][lgn];
vector <ll> depth(mxn);

// Start of Heavy Light Decomposition
vector <ll> heavy(mxn);
vector <ll> sid(mxn);
vector <ll> Index(mxn);
vector <vector <ll>> chains(mxn);

ll hldInit(ll root, ll par){
	if(root == par){
		depth[root] = 0;
	}

	ll curCnt = 0;

	for(auto it : adj[root]){
		if(it != par){
			depth[it] = depth[root] + 1;
			up[it][0] = root;
			curCnt += hldInit(it, root);
		}
	}

	return childCnt[root] = 1 + curCnt;
}

void hldMark(ll root, ll par){

	ll mx = -1;
	heavy[root] = -1;

	for(auto it : adj[root]){
		if(it != par){

			if(childCnt[it] > mx){
				mx = childCnt[it];
				heavy[root] = it;
			}

			hldMark(it, root);
		}
	}
}

ll id = 0;

void hld(ll root, ll par){

	sid[root] = id;
	chains[id].pb(root);
	Index[root] = chains[id].size() - 1;

	for(auto it : adj[root]){
		if(it != par && it == heavy[root]){
			hld(it, root);
			break;
		}
	}

	for(auto it : adj[root]){
		if(it != par && it != heavy[root]){
			++id;
			hld(it, root);
		}
	}
}

 
void buildUp(ll root, ll par){
	if(root == 0) depth[root] = 1;
 
	for(auto it : adj[root]){
		if(it == par) continue;
 
		up[it][0] = root;		
		depth[it] = depth[root] + 1;
 
		for(ll i = 1; i < lgn; ++i){
			if(up[it][i - 1] != -1) up[it][i] = up[up[it][i - 1]][i - 1];
		}
 
		buildUp(it, root);
	}
}
 
ll getLCA(ll a, ll b){
 
	if(depth[a] < depth[b]){
		swap(a, b);
	}
 
	for (ll i = lgn - 1; i >= 0; --i) {
        if (depth[a] - depth[b] >= (1 << i)) {
            if (a != -1) {
                a = up[a][i];
            }
        }
    }
 
    if(a == b) return a;
 
    for(ll i = lgn - 1; i >= 0; --i){
    	if(up[a][i] != up[b][i]){
    		a = up[a][i];
    		b = up[b][i];
    	}
    }
 
    if(up[a][0] == -1) return -1;
    return up[a][0];
}

ll pathMax(ll l, ll r){
	
	ll lca = getLCA(l, r);
	ll ans = INT_MIN;

	while(1){
		if(sid[l] != sid[lca]){

			// cout << l << " " << sid[l] << " : " << 0 << " " << Index[l] + 1 << " : " << query(0, Index[l], chainsSGT[sid[l]].size(), chainsSGT[sid[l]]) << "\n";
			ans = max(ans, query(0, Index[l] + 1, chains[sid[l]].size(), sid[l]));
			
			ll head = chainsSGT[sid[l]][0];
			l = up[head][0];
		}
		else{
			ans = max(ans, query(Index[lca], Index[l] + 1, chains[sid[l]].size(), sid[l]));
			break;
		}
	}

	while(1){
		if(sid[r] != sid[lca]){
			ans = max(ans, query(0, Index[r] + 1, chains[sid[r]].size(), sid[l]));
			
			ll head = chainsSGT[sid[r]][0];
			r = up[head][0];
		}
		else{
			ans = max(ans, query(Index[lca], Index[r] + 1, chains[sid[r]].size(), sid[l]));
			break;
		}
	}


	return ans;
}

// Solve

void solve() {
 	ll n, q;
 	cin >> n >> q;

 	vector <ll> v(n);
 	read(v, i, n);

 	for(ll i = 0; i < n - 1; ++i){
 		ll u, v;
 		cin >> u >> v;

 		--u, --v;

 		adj[u].pb(v);
 		adj[v].pb(u);
 	}

 	hldInit(0, 0);
 	hldMark(0, 0);
 	hld(0, 0);

 	buildUp(0, 0);

 	for(ll i = 0; i <= id; ++i){

 		vector <ll> tmp(chains[i].size());
 		for(ll j = 0; j < chains[i].size(); ++j){
 			tmp[j] = v[chains[i][j]];
 		}

 		chainsSGT[i].resize(2 * chains[i].size() + 5);

 		build(tmp, tmp.size(), i);
 	}

 	// for(ll i = 0; i <= id; ++i){
 	// 	cout << i << " : ";
 	// 	print(chainsSGT[i], j, chainsSGT[i].size());
 	// }


 	// cout << "Test : " << query(0, 2, chainsSGT[0].size(), chainsSGT[0]) << "\n";

	while(q--){
	 	ll t;
	 	cin >> t;

	 	if(t == 1){
	 		ll s, x;
	 		cin >> s >> x;

	 		--s;

	 		// Update operation
	 		update(Index[s], x, chains[sid[s]].size(), sid[s]);
	 	}
	 	else{
	 		ll a, b;
	 		cin >> a >> b;

	 		--a, --b;

	 		// Find path max between a to b
	 		cout << pathMax(a, b) << " ";
	 	}
	 }

}

int main(){
    
    fast();

        solve();
    

    return 0;
}