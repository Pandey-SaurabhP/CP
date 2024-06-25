
#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n, x;
    cin >> n >> x;

    vector <long long> a(n);
    for(long long i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector <long long> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for(long long i = 0; i < n; ++i){
        if(a[i] <= x) dp[a[i]] = 1;
    }

    for(long long i = 0; i <= x; ++i){
        for(long long j = 0; j < n; ++j){
            if(i - a[j] >= 0){
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if(dp[x] == INT_MAX){
        cout << -1;
    }
    else cout << dp[x];

    return 0;
}
