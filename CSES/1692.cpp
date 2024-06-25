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

vector <vector <int>> adj(mxn, vector <int> (2));
vector <int> in(mxn, 0), out(mxn, 0);

vector  <int> path;

void dfs(int root){

	while(adj[root].size()){

		int m = adj[root].size();
		int it = adj[root][m - 1];

		adj[root].pop_back();

		dfs(it);
	}

	path.pb(root);
}

void solve() {
    
    int n;
    cin >> n;

    --n;

    if(n == 0){
    	cout << "01\n";
    	return	;
    }

    for(int i = 0; i < (1 << n); ++i){
    	// Assume we are currently at ith number

    	adj[i][0] = (i & ((1 << (n - 1)) - 1));
    	adj[i][0] <<= 1;

    	adj[i][1] = (i & ((1 << (n - 1)) - 1));
    	adj[i][1] <<= 1; adj[i][1] |= 1;

    	in[adj[i][0]]++, in[adj[i][1]]++;
    	out[i] += 2;
    }

    // for(int i = 0; i < (1 << n); ++i){
    // 	cout << i << " : " << adj[i][0] << " " << adj[i][1] << "\n";
    // }

    // Now find an euler path in the given graph

    // Indegree must be even for all, except two

    // Now run the algo



    dfs(0);

    // print(path, i, path.size());
    reverse(path.begin(), path.end());

    for(int i = 0; i < n - 1; ++i) cout << 0;

    for(int i = 0; i < path.size(); ++i){
    	cout << path[i] % 2;
    }
    cout << "\n";


}

int main(){
    
    fast();

    solve();

    return 0;
}