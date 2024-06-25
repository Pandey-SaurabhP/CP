#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

// DSU

ll dfs(ll root, map <ll, vector <ll>> &adj, set <ll> &vis, map <ll, ll> &color, ll c){
	color[root] = c;
	vis.insert(root);
	for(auto it : adj[root]){
		if(!vis.count(it)){
			dfs(it, adj, vis, color, c);
		}
	}
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    map <ll, vector <ll>> mp;

    rep(i, 0, n){
    	mp[a[i]].pb(i);
    }

    map <ll, vector <ll>> adj;

    rep(i, 0, n){
    	if(mp.count(a[i] ^ 1)){
    		adj[a[i]].pb(a[i] ^ 1);
    	}
    	if(mp.count(a[i] ^ 2)){
    		adj[a[i]].pb(a[i] ^ 2);
    	}
    	if(mp.count(a[i] ^ 3)){
    		adj[a[i]].pb(a[i] ^ 3);
    	}
    }

    set <ll> vis;
    map <ll, ll> color;
    
    ll c = 0;

    for(int i = 0; i < n; ++i){
    	if(!vis.count(a[i])){
    		++c;
    		dfs(a[i], adj, vis, color, c);
    	}
    }

    vector <vector <int>> sorted(c + 1);

    for(int i = 0; i < n; ++i){
    	sorted[color[a[i]]].pb(a[i]);
    }

    for(int i = 0; i <= c; ++i){
    	sort(sorted[i].begin(), sorted[i].end());
    }

    for(int i = n - 1; i >= 0; --i){
    	int sz = sorted[color[a[i]]].size();
    	a[i] = sorted[color[a[i]]][sz - 1];
    	sorted[color[a[i]]].pop_back();
    }

    print(a, i, n);
}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}