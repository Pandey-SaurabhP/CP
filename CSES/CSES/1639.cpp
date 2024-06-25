#include <bits/stdc++.h>

using namespace std;

int dp[5005][5005];

int main(){
    string s, t;
    cin >> s >> t;

    for(int i = 0; i <= s.size(); ++i){
        for(int j = 0; j <= t.size(); ++j){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else if(s[i - 1] == t[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min(1 + dp[i - 1][j], min(1 + dp[i][j - 1], 1 + dp[i - 1][j - 1]));
            }
        }
    }

    cout << dp[s.size()][t.size()] << "\n";

    return 0;
}
