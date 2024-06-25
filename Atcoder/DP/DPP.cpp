// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <ll>> adj(mxn);
ll dp[mxn][2];

void solve(ll root, ll par){

    dp[root][0] = 1ll;
    dp[root][1] = 1ll;

    for(auto it : adj[root]){
        if(it != par){
            solve(it, root);

            dp[root][0] *= (dp[it][0] + dp[it][1]) % mod;
            dp[root][1] *= dp[it][0];

            dp[root][0] %= mod;
            dp[root][1] %= mod;
        }
    }
}

int main(){

    // fast();

    ll n;
    cin >> n;

    for(ll i = 0; i < n - 1; ++i){
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1, -1);

    cout << (dp[1][0] + dp[1][1]) % mod;
    
    return 0;
}