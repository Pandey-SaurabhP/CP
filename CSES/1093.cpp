#include <bits/stdc++.h>

using namespace std;

long long dp[501][125001];
long long mod = 1e9 + 7;

long long solve(long long i, long long sm, long long &n){
    if(i == n){
        return (sm == ((n * (n + 1)) / 4));
    }

    if(dp[i][sm] != -1){
        return dp[i][sm];
    }

    long long a1 = solve(i + 1, sm + i, n);
    long long a2 = solve(i + 1, sm, n);

    return dp[i][sm] = (a1 + a2) % mod;
}

long long fastPower(long long base, long long exp){

    long long ans = 1;

    while(exp){
        if(exp % 2 == 1){
            ans *= base;
            ans %= mod;
            --exp;
        }
        else{
            base *= base;
            base %= mod;
            exp >>= 1ll;
        }
    }

    return ans % mod;
}

int main(){
    memset(dp, -1, sizeof(dp));

    long long n;
    cin >> n;

    if(((n * (n + 1)) / 2) % 2 == 1){
        cout << 0;
    }
    else{
       long long mm = fastPower(2, mod - 2);

       mm *= solve(0, 0, n);

       mm %= mod;

       cout << mm;
    }

    return 0;
}
