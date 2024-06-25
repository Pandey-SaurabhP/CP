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
#define read(a, i, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(int i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";
 
// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
// Constants
const int mxn = 2e5 + 5;
const int mod = 1e9 + 7;
const int lgn = 22;
 
// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
// Segment Tree for sum, point update range query
vector <vector <int>> segTree(mxn);
int qwerty = 0;
vector <int> segTreeTmp;
 
void update(int l, int r, int i, int x, int v, vector <int> &sg){
    if(l == r){
        sg[i] = v;
        return;
    }
 
    int mid = (l + r) / 2;
 
    if(mid >= x) update(l, mid, 2 * i + 1, x, v, sg);
    else update(mid + 1, r, 2 * i + 2, x, v, sg);
    
 
    sg[i] = max(sg[2 * i + 1], sg[2 * i + 2]);
}
 
void build(int l, int r, int i, vector <int> &a, int &n, vector <int> &sg){
    if(l == r){
        sg[i] = a[l];
        return;
    }
 
    int mid = (l + r) / 2;
 
    build(l, mid, 2 * i + 1, a, n, sg);
    build(mid + 1, r, 2 * i + 2, a, n, sg);
 
    sg[i] = max(sg[2 * i + 1], sg[2 * i + 2]); 
}
 
int query(int l, int r, int i, int lll, int rr, vector <int> &sg){
    if(r < lll || l > rr) return INT_MIN;
 
    if(l >= lll && r <= rr){
        return sg[i];
    }
 
    int mid = (l + r) / 2;
 
    return max(query(l, mid, 2 * i + 1, lll, rr, sg), query(mid + 1, r, 2 * i + 2, lll, rr, sg));
}
 
 
// HLD + Solve
vector <int> parent(mxn, -1);
vector <vector <int>> adj(mxn);
vector <int> maxDepth(mxn);
vector <vector <int>> chains(mxn);
vector <int> chainId(mxn);
 
vector <int> Index(mxn, -1);
int c = 0;
 
// DFS
int fillDepth(int root, int par){
	int d = 0;
	int cnt = 0;
 
	for(auto it : adj[root]){
		if(it != par){
			parent[it] = root;
			d += fillDepth(it, root);
		}
	}
 
 
	return maxDepth[root] = d + 1;
}
 
set <pii> heavy;
 
void hld(int root, int par = 0){
	int mx = maxDepth[root];
 
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
 
int id = 0;
 
void buildHLD(int root, int par = 0){
	chains[id].pb(root);
	chainId[root] = id;
	Index[root] = chains[id].size() - 1;
 
	int mxId = -1;
 
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
		if(root == 0) depth[root] = 1;
 
	for(auto it : adj[root]){
		if(it == par) continue;
 		
 
		up[it][0] = root;		
		depth[it] = depth[root] + 1;
 
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
        if (depth[a] - depth[b] >= (1 << i)) {
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
	memset(up, -1, sizeof(up));
 
	int n, m;
	cin >> n >> m;
 
	vector <int> v(n);
	read(v, i, n);
 
	for(int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;
 
		--u, --v;
 
		adj[u].pb(v);
		adj[v].pb(u);
	}
 
	fillDepth(0, 0);
	hld(0);
	buildHLD(0, 0);
 
	for(int i = 0; chains[i].size() != 0; ++i){
 
		segTreeTmp.resize(4 * chains[i].size());
		int sz = chains[i].size();
 
		vector <int> values(chains[i].size());
 
		for(int j = 0; j < chains[i].size(); ++j){
			values[j] = v[chains[i][j]];
		} 
 
		build(0, chains[i].size() - 1, 0, values, sz, segTreeTmp);
 
		segTree[qwerty++] = segTreeTmp;
	}
 
	// for(int i = 0; i < segTree[0].size(); ++i){
	// 	cout << segTree[0][i] << " ";
	// }
	// cout << "\n";
 
	
 
	buildUp(0, 0);
 
	// for(int i = 0; i < 10; ++i){
	// 	cout << i << " : ";
	// 	for(int j = 0; j < 4; ++j){
	// 		cout << up[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
 
	for(int i = 0; i < m; ++i){
 
		int type;
		cin >> type;
 
		if(type == 2){
			int u, v;
			cin >> u >> v;
 
			--u, --v;
			int lca = getLCA(u, v);
 
			// cout << u << " " << v << " : " << lca << "\n";
 
			int smu = INT_MIN;
			int liesLCA = chainId[lca];
 
 
			while(u != -1){
				int liesIn = chainId[u];
 
				// cout << u << " " << lca << " : " << liesIn << " " << liesLCA << " :  " << smu << "\n"	; 
 
				if(liesIn != liesLCA){
					smu = max(query(0, chains[liesIn].size() - 1, 0, 0, Index[u], segTree[liesIn]), smu);
					u = parent[chains[liesIn][0]];
				}
				else{
					smu = max(query(0, chains[liesIn].size() - 1, 0, Index[lca], Index[u], segTree[liesIn]), smu);
					// u = -1;
					break;
				}
 
			}
 
			// cout << smu << "\n";
 
			while(v != -1){
				int liesIn = chainId[v];
				// cout << v << " " << lca << " : " << liesIn << " " << liesLCA << " :  " << smu << "\n"	; 
 
				if(liesIn != liesLCA){
					smu = max(query(0, chains[liesIn].size() - 1, 0, 0, Index[v], segTree[liesIn]), smu);
					v = parent[chains[liesIn][0]];
				}
				else{
					smu = max(query(0, chains[liesIn].size() - 1, 0, Index[lca], Index[v], segTree[liesIn]), smu);
					// v = -1;
					break;
				}
			}
 
			cout << smu << " ";
		}
		else{
			int u, val;
			cin >> u >> val;
 
			--u;
 
			int liesIn = chainId[u];
			int id = Index[u];
 
			update(0, chains[liesIn].size() - 1, 0, id, val, segTree[liesIn]);	
		}
	}
}
 
int main(){
    fast();
    solve();
 
    return 0;
}