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

vector <vector <ll>> matrixMultiply(vector <vector <ll>> a, vector <vector <ll>> b, ll n){
    vector <vector <ll>> ans(n, vector <ll> (n, 0));

    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            for(ll k = 0; k < n; ++k){
                ans[i][j] += (a[i][k] * b[k][j]) % mod;
                ans[i][j] %= mod;
            }
        }
    }

    return ans;
}

vector <vector <ll>> fastPower(vector <vector <ll>> b, ll e){

    vector <vector <ll>> ans(b.size(), vector <ll> (b.size(), 0));

    for(ll i = 0; i < b.size(); ++i){
        ans[i][i] = 1;
    }

    while(e){

        if(e & 1){
            ans = matrixMultiply(ans, b, b.size());
        }
       
        b = matrixMultiply(b, b, b.size());
        e >>= 1;
        
    }

    return ans;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector <vector <ll>> a(n, vector <ll> (n, 0));

    for(ll i = 0; i < m; ++i){
        ll u, v;
        cin >> u >> v;

        --u, --v;

        a[u][v] += 1;
    }


    vector <vector <ll>> fna = fastPower(a, k);

    cout << fna[0][n - 1] << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}