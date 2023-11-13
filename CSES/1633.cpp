#include <bits/stdc++.h>
using namespace std;

long long dp[1000005];
long long mod = 1e9 + 7;

long long solve(long long x){
    if(x < 0) return 0;
    if(x == 0) return 1;

    if(dp[x] != -1) return dp[x];

    long long ans = 0;

    for(long long i = 1; i <= 6; ++i){
        ans += solve(x - i);
        ans %= mod;
    }

    return dp[x] = ans % mod;
}

int main(){

    for(long long i = 0; i < 1000005; ++i){
        dp[i] = -1;
    }

    long long n;
    cin >> n;

    cout << solve(n);
    return 0;
}
