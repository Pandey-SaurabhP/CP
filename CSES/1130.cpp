#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
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

vector <vector <int>> adj(mxn);

vector <vector <int>> sides(2);

void slv(int root, int par, int side){
	sides[side].pb(root);

	for(auto it : adj[root]){
		if(it != par){
			slv(it, root, side ^ 1);
		}
	}
}

void hopcroft(){

	vector <int> pu(	)
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

    cout << done.size() << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}