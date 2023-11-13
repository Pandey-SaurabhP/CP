#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll dp[5001][5001];

ll inf = 2e18;

ll solve(ll l, ll r, bool chance, vector <ll> &a){
    if(l == r){
        return (chance == 0? a[l]: 0);
    }

    if(dp[l][r] != -inf){
        return dp[l][r];
    }

    ll a1 = solve(l + 1, r, chance ^ 1, a);
    ll a2 = solve(l, r - 1, chance ^ 1, a);

    if(chance == 0){
        return dp[l][r] = max(a[l] + a1, a[r] + a2);
    }
    else{
        return dp[l][r] = min(a1, a2);
    }
}

int main(){

    for(ll i = 0; i < 5001; ++i){
        for(ll j = 0; j < 5001; ++j){
            dp[i][j] = -inf;
        }
    }
    ll n;
    cin >> n;

    vector <ll> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
    }

    cout << solve(0, n - 1, 0, a);

    return 0;
}
