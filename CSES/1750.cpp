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
#define read(par, i, n) for(ll i = 0; i < n; ++i) cin >> par[i];
#define print(par, i, n) for(ll i = 0; i < n; ++i){ cout << par[i] << " ";} cout << "\n";
 
// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;
 
 
typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;
 
// Constants
const ll mxn = 2e5 + 5;
const ll mod = 1e9 + 7;
const int lgn = 32;
 
// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
// Solve
vector <vector <int>> adj(mxn);
ll up[mxn][lgn];
 
int getKth(int root, int k){
 
    for(int j = 0; j < lgn; ++j){
        if(k & (1 << j)){
            root = up[root][j];
        }
    }
 
    return root + 1;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector <int> par(n);
    read(par, i, n);
 
    for(int i = 0; i < n; ++i){
        adj[i].pb(par[i] - 1);
        up[i][0] = par[i] - 1;
    }
 
 
    for(int j = 1; j < lgn; ++j){
        for(int v = 0; v < n; ++v){
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }
 
    while(q--){
        int x, k;
        cin >> x >> k;
 
        --x;
 
        cout << getKth(x, k) << "\n";
    }
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}
