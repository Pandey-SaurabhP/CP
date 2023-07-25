// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll inf = -1e18;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll dp[405][405];


ll solve(ll l, ll r, vector <ll> &a){
    if(l == r){
        return a[l];
    }

    if(dp[l][r] != -1ll){
        return dp[l][r];
    }

    ll mn = -inf;

    ll sm = 0ll;
    for(ll i = l; i <= r; ++i) sm += a[i];
    
    for(ll i = l; i < r; ++i){
        mn = min(mn, sm + solve(l, i, a) + solve(i + 1, r, a));
    }

    return dp[l][r] = mn;
}

int main(){

    // fast();
    for(int i = 0; i < 405; ++i){
        for(int j = 0; j < 405; ++j){
            dp[i][j] = INT_MAX;
        }
    }

    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, n);

    vector <ll> pre(n + 1, 0);
    for(int i = 0; i < n; ++i){
        dp[i][i] = a[i];
        pre[i + 1] = a[i] + pre[i];
    }

    
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            
            for(int k = i; k < j; ++k){
                dp[i][j] = min(dp[i][j], (pre[j + 1] - pre[i]) + dp[i][k] + dp[k + 1][j]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(dp[i][j] != INT_MAX) cout << dp[i][j] << "\t";
            else cout << -1 << "\t";
        }
        cout << "\n";
    }


    cout << dp[0][n - 1] - pre[n] << "\n";

    memset(dp, -1, sizeof(dp));
    cout << dp[0][1] << "\n";
    cout << solve(0ll, n - 1ll, a) - accumulate(a.begin(), a.end(), 0ll);
    
    return 0;
}