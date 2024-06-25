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

// Solve

vector <vector <int>> adj(mxn);
vector <set <int>> vc(mxn);
vector <int> ans(mxn, 1);

void slv(int root, int par){

	for(auto it : adj[root]){

		// Small to Large merging
		if(it != par){
			slv(it, root);

			if(vc[root].size() < vc[it].size()){
				swap(vc[it], vc[root]);
			}

			for(auto jt : vc[it]){
				vc[root].insert(jt);
			}

			ans[root] = vc[root].size();
		}
	}
}

void solve() {
    
    int n;
    cin >> n;

    vector <int> v(n);
    read(v, i, n);

    for(int i = 0; i < n; ++i){
    	vc[i].insert(v[i]);
    }

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    slv(0, 0);

    print(ans, i, n);
}

int main(){
    
    fast();
    solve();
    
    return 0;
}