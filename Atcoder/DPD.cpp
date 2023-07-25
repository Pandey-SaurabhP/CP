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

ll dp[101][100005]; // Minimum weight for a maximumvalue

int main(){

    // fast();
    memset(dp, -1, sizeof(dp));

    ll n, w;
    cin >> n >> w;

    vector <ll> wt(n), val(n);

    for(ll i = 0; i < n; ++i){
        cin >> wt[i] >> val[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= w; ++j){
            
            if(i == 0){
                if(j - wt[i] >= 0) dp[i][j] = val[i];
            }

            if(i - 1 >= 0) dp[i][j] = dp[i - 1][j];
            if(j - wt[i] >= 0 && i - 1 >= 0) dp[i][j] = max(dp[i][j], val[i] + dp[i - 1][j - wt[i]]);
        }
    }

    cout << dp[n - 1][w];

    return 0;
}