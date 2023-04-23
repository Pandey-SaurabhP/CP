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

int main(){

    // fast();

    ll h, w;
    cin >> h >> w;

    // cout << h << " " << w << "\n";

    vector <string> a(h);

    for(ll i = 0; i < h; ++i){
        cin >> a[i];
    }

    vector <vector <ll>> dp(h, vector <ll> (w));

    for(ll i = 0; i < h; i++){
        for(ll j = 0; j < w; ++j){
            if(i == 0 && j == 0){
                if(a[i][j] == '#'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1;
                }
            }
            else if(i == 0){
                if(a[i][j] != '#'){
                    dp[i][j] = dp[i][j - 1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else if(j == 0){
                if(a[i][j] != '#'){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else{
                if(a[i][j] == '#'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    // for(ll i = 0; i < h; ++i){
    //     for(ll j = 0; j < w; ++j){
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    cout << dp[h - 1][w - 1];
    
    return 0;
}