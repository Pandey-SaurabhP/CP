#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int main(){

    int n;
    cin >> n;

    vector <string> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int dp[n + 1][n + 1];

    if(a[0][0] == '*'){
        cout << 0;
    }
    else{
        dp[0][0] = 1;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0) continue;
                else if(i == 0){
                    dp[i][j] = (a[i][j] == '*'? 0: dp[i][j - 1]);
                }
                else if(j == 0){
                    dp[i][j] = (a[i][j]== '*'? 0: dp[i - 1][j]);
                }
                else{
                    dp[i][j] = (a[i][j] == '*'? 0: dp[i - 1][j] + dp[i][j - 1]);
                }

                dp[i][j] %= mod;
            }
        }

        cout << dp[n - 1][n - 1];
    }
    return 0;
}
