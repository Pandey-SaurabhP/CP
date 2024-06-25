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

int farthest = 0;
int fd = 0;

void getFarthest(int root, int par, int d){
	if(d > fd){
		farthest = root;
		fd = d;
	}

	for(auto it : adj[root]){
		if(it != par){
			getFarthest(it, root, d + 1);
		}
	}
}

void solve() {
    
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u;
    	--v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    getFarthest(0, 0, 0);
    fd = 0;
    getFarthest(farthest, farthest, 0);

    cout << fd << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}