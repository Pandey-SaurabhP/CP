#include <bits/stdc++.h>

using namespace std;
long long mod = 1e9 + 7;

long long dp[1000001];

int main(){

    for(long long i = 0; i < 1000001; ++i){
        dp[i] = INT_MAX;
    }

    dp[0] = 0ll;

    long long x;
    cin >> x;

    for(int i = 1ll; i <= x; ++i){

        long long tmp = i;

        while(tmp){
            long long ld = tmp % 10ll;

            if(ld != 0ll && i - ld >= 0ll){
                dp[i] = min(dp[i], dp[i - ld] + 1);
            }

            tmp /= 10ll;
        }
    }

    cout << dp[x];

    return 0;
}

