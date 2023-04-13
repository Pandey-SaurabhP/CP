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

void solve(int i, int rSum, int bSum, vector <int> &r, vector <int> &b, int &n, vector <vector <int>> &dp, int &ans){

    if(i == n){
        ans = max(ans, min(bSum, rSum));
        return;
    }

    if(bSum <= dp[i][rSum] && dp[i][rSum] != 0){
        return;
    }

    solve(i + 1, rSum + r[i], bSum, r, b, n, dp, ans);
    solve(i + 1, rSum, bSum + b[i], r, b, n, dp, ans);

    dp[i][rSum] = bSum;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        vector <int> r(n);
        vector <int> b(n);

        read(r, n);
        read(b, n);

        vector <vector <int>> dp(n + 1, vector <int> (20001));

        int ans = INT_MIN;
        solve(0, 0, 0, r, b, n, dp, ans);

        cout << ans << "\n";

        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= 15; ++j){
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }

    }
    
    return 0;
}