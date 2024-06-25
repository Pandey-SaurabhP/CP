// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll inf = 1e11;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll dp[101][100005]; // Minimum weight for a maximum value

int main(){

    // fast();

    ll n, w;
    cin >> n >> w;

    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < 100005; ++j){
            dp[i][j] = INT_MAX;
        }
    }

    // cout << "Hello!\n";

    vector <ll> wt(n), val(n);

    for(ll i = 0; i < n; ++i){
        cin >> wt[i] >> val[i];
    }

    dp[0][0] = 0;
    dp[0][val[0]] = wt[0];
    
    for(ll i = 1; i < n; ++i){
        dp[i][0] = 0;
        for(ll j = 1; j < 100005; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j - val[i] >= 0) dp[i][j] = min(dp[i][j], wt[i] + dp[i - 1][j - val[i]]);
        }
    }

    // cout << "Hello!\n";

    ll ans = INT_MIN;

    for(ll i = 100004; i >= 0; --i){
        for(ll j = 0; j < n; ++j){
            if(dp[j][i] <= w){
                ans = i;
                break;
            }
        }

        if(ans != INT_MIN){
            break;
        }
    }

    // for(ll i = 0; i < n; ++i){
    //     for(ll j = 0; j < 15; ++j){
    //         if(dp[i][j] != INT_MAX) cout << dp[i][j] << " ";
    //         else cout << "U ";
    //     }
    //     cout << "\n"; 
    // }

    cout << ans;

    return 0;
}