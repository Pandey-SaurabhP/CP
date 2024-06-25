#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <int>> adj(mxn), rev(mxn);
stack <int> st;

set <int> visited1, visited2;

vector <vector <int>> comps(mxn);
int sz = 0;


void dfs(int root){
	visited1.insert(root);
	for(auto it : adj[root]){
		if(!visited1.count(it)){
			visited1.insert(it);
			dfs(it);
		}
	}
	st.push(root);
}

void dfs2(int root){
	visited2.insert(root);
	comps[sz].pb(root);
	for(auto it : rev[root]){
		if(!visited2.count(it)){
			visited2.insert(it);
			dfs2(it);
		}
	}
}


void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v;

    	adj[u].pb(v);
    	rev[v].pb(u);
    }

    for(int i = 1; i <= n; ++i){
    	if(!visited1.count(i)){
    		dfs(i);
    	}
    }

    while(!st.empty()){
    	int tp = st.top();
    	st.pop();

    	if(!visited2.count(tp)){
    		++sz;
    		dfs2(tp);
    	}
    }

    vector <int> ans(n + 1);

    for(int i = 0; i <= sz; ++i){
    	for(auto it : comps[i]){
    		ans[it] = i;
    	}
    }

    cout << sz << "\n";
    rep(i, 1, n + 1){
    	cout << ans[i] << " ";
    }
    cout << "\n";

}

int main(){
    
    fast();

    solve();

    return 0;
}