// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    // fast();

    int n;
    cin >> n;

    vector <vector <int>> a(n, vector <int> (3));

    for(int i = 0; i < n; ++i){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    vector <vector <int>> dp(n, vector <int> (3, 0));

    dp[0] = a[0];

    for(int i = 1; i < n; ++i){
        dp[i][0] = a[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = a[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = a[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    
    return 0;
}