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

void getFarthest(int root, int par, int dist, pii &param){
	if(dist > param.ss){
		param.ff = root;
		param.ss = dist;
	}

	for(auto it : adj[root]){
		if(it != par){
			getFarthest(it, root, 1 + dist, param);
		}
	}
}

bool cmp(pii a, pii b){
	if(a.ss > b.ss){
		return 1;
	}
	else if(a.ss < b.ss){
		return 0;
	}
	else{
		return (a.ff > b.ff);
	}
}

int dist1[mxn];
void dfs1(int root, int par, int d){
	dist1[root] = d;
	for(auto it : adj[root]){
		if(it != par){
			dfs1(it, root, d + 1);
		}
	}
}

int dist2[mxn];
void dfs2(int root, int par, int d){
	dist2[root] = d;
	for(auto it : adj[root]){
		if(it != par){
			dfs2(it, root, d + 1);
		}
	}
}

int ans[mxn];

void dfs3(int root, int par){
	ans[root] = max(dist1[root], dist2[root]);

	for(auto it : adj[root]){
		if(it != par) dfs3(it, root);
	}
}


void solve() {

    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);

    }

    vector <pii> dist;

    for(auto it : adj[0]){
    	pii pr = {0, 0};
    	getFarthest(it, 0, 1, pr);
    	dist.pb(pr);
    }

    if(dist.size() == 0){
    	dist.pb({0, 0});
    }

    sort(dist.begin(), dist.end(), cmp);
    int d1 = dist[0].ff;

    // for(auto it : dist){
    // 	cout << it.ff << " " << it.ss << "\n";
    // }

	dfs1(d1, d1, 0);

	pii pr;
	getFarthest(d1, d1, 0, pr);

	int d2 = pr.ff;

	dfs2(d2, d2, 0);
	dfs3(0, 0);


	print(ans, i, n);
    
}

int main(){
    
    fast();

        solve();
    

    return 0;
}