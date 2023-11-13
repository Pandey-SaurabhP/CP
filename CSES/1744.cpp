#include <bits/stdc++.h>

using namespace std;

int dp[505][505];

int main(){
    for(int i = 0; i < 505; ++i){
        for(int j = 0; j < 505; ++j){
            dp[i][j] = 1000001;
        }
    }

    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){

            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(i == j){
                dp[i][j] = 0;
            }
            else{
                for(int k = 1; k < j; ++k){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
                }

                for(int k = 1; k < i; ++k){
                    dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
                }
            }
        }
    }

    cout << dp[n][m];

    return 0;
}
