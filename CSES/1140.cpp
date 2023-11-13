#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    long long x[n], y[n], z[n];
    for(long long i = 0 ;i < n; ++i){
        cin >> x[i] >> y[i] >> z[i];
    }

    set <long long> st;

    for(int i = 0; i < n; ++i){
        st.insert(x[i]);
        st.insert(y[i]);
    }

    map <long long, long long> mp;
    long long mx = 1;

    for(auto it : st){
        mp[it] = mx;
        ++mx;
    }

    for(long long i = 0; i < n; ++i){
        x[i] = mp[x[i]];
        y[i] = mp[y[i]];
    }

    vector <vector <pair <long long, long long>>> vc2(mx + 1);

    for(long long i = 0; i < n; ++i){
        vc2[y[i]].push_back({x[i], z[i]});
    }

    long long dp[mx + 1];
    dp[0] = 0;

    for(long long i = 1; i < mx; ++i){
        dp[i] = dp[i - 1];
        for(auto it : vc2[i]){
            dp[i] = max(dp[i], dp[it.first - 1] + it.second);
        }
    }

    cout << dp[mx - 1];


    return 0;
}

//10
//14 14 98
//76 76 58
//94 94 57
//92 92 45
//82 82 14
//86 86 41
//87 87 72
//14 14 26
//27 27 85
//48 48 52
