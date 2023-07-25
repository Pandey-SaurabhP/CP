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

ll dp[200002][65];

ll cntBit(ll x){
    ll cnt = 0;

    while(x){
        if(x & 1){
            ++cnt;
        }

        x >>= 1;
    }

    return cnt;
}

ll solve(ll i, ll x, vector <ll> &a, ll &k){
    if(i == a.size()){
        return (cntBit(x) == k);
    }

    if(dp[i][x] != -1){
        return dp[i][x];
    }

    ll ans = 0;

    ans += solve(i + 1, x & a[i], a, k);
    ans %= mod;

    ans += solve(i + 1, x, a, k);
    ans %= mod;

    return dp[i][x] = ans;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector <ll> a(n);
        read(a, n);

        for(ll i = 0; i <= n; ++i){
            for(ll j = 0; j < 65; ++j){
                dp[i][j] = -1;
            }
        }

        if(k == 6){
            cout << solve(0, 63, a, k) - 1 << "\n";
        }
        else{
            cout << solve(0, 63, a, k) << "\n";
        }
    }
    
    return 0;
}