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

ll solve2(vector <ll> &a, ll &n, ll &k){

    vector <vector <ll>> dp(n + 5, vector <ll> (k + 5, 0ll));
    dp[0][0] = 1ll;

    for(ll j = 0; j <= a[0]; ++j){
        dp[1][j] = 1ll;
    }

    vector <ll> pref(k + 1, 0ll);

    for(ll i = 2; i <= n; ++i){

        pref[0] = dp[i - 1][0];
        for(ll j = 1; j <= k; ++j){
            pref[j] = dp[i - 1][j] + pref[j - 1];
            pref[i] %= mod;
        }

        for(ll j = 0; j <= k; ++j){
            dp[i][j] += pref[j];
            
            if(j - a[i - 1] > 0ll){
                dp[i][j] -= pref[j - a[i - 1] - 1ll];
            }

            dp[i][j] %= mod;
            dp[i][j] += mod;
            dp[i][j] %= mod;
        }
    }

    return dp[n][k] % mod;
}

int main(){

    // fast();

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, n);

    cout << solve2(a, n, k);

    return 0;
}