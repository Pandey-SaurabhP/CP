
#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n, x;
    cin >> n >> x;

    vector <long long> dp(x + 1, 0);
    dp[0] = 0;

    vector <long long> a(n);
    for(long long i = 0; i < n; ++i){
        cin >> a[i];

        if(a[i] <= x){
            dp[a[i]] = 1;
        }
    }

    sort(a.begin(), a.end());

    for(long long i = 1; i <= x; ++i){
        long long id = upper_bound(a.begin(), a.end(), i) - a.begin();
        for(long long j = 0; j < id; ++j){
            dp[i] += dp[i - a[j]];
        }
        dp[i] %= mod;
    }

    cout << dp[x];

    return 0;
}

