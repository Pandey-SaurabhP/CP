#include <bits/stdc++.h>

using namespace std;
int mod = 1e9 + 7;

int dp[101][1000001];


int main(){

    for(int i = 0; i < 101; ++i){
        for(int j = 0; j < 1000001; ++j){
            dp[i][j] = 0;
        }
    }

    int n, x;
    cin >> n >> x;

    vector <int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }


    for(int i = 0; i < n; ++i){
        dp[i][a[i]]++;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= x; ++j){

            if(i - 1 >= 0) dp[i][j] += dp[i - 1][j];
            if(j - a[i] >= 0) dp[i][j] += dp[i][j - a[i]];

            dp[i][j] %= mod;

        }
    }

    cout << dp[n - 1][x];

    return 0;
}
