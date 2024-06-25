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

void solve() {
    int n;
    cin >> n;

    int m = n;

    bool mat[n][m];

    vector <vector <int>> adj(n);

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		cin >> mat[i][j];

    		if(mat[i][j] == 1){
    			adj[i].pb(j);
    		}
    	}
    }

    for(int i = 0; i < n; ++i){
    	for(auto it : adj[i]){
    		cout << it + 1 << " ";
    	}
    	cout << "\n";
    }
}

int main(){
    
    fast();

    solve();
    return 0;
}