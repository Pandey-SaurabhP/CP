// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const ll mxn = (1 << 21) + 100;
ll dp[22][mxn];

ll solve(ll i, ll blocked, vector <vector <ll>> &a, ll &n, ll &x){

    if(i == n){
        // cout << "Blocked : " << blocked << "\n";
        return (blocked == x);
    }

    if(dp[i][blocked] != -1){
        return dp[i][blocked];
    }

    ll ans = 0;

    for(ll j = 0; j < n; ++j){

        ll r = blocked >> j;

        if((a[i][j] == 1) && !(r & 1)){
            ans += solve(i + 1, blocked | (1 << j), a, n, x);
            ans %= mod;
        }
    }

    return dp[i][blocked] = ans % mod;
}

int main(){

    // fast();
    memset(dp, -1, sizeof(dp));

    ll n;
    cin >> n;

    vector <vector <ll>> a(n, vector <ll> (n));

    ll x = 1 << n;
    --x;

    for(ll j = 0; j < n; ++j){
        read(a[j], n);
    }

    // for(auto it : a){
    //     for(auto jt : it){
    //         cout << jt << " ";
    //     }
    //     cout << "\n";
    // }

    cout << solve(0, 0, a, n, x);
    
    return 0;
}