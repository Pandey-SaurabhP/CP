// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int dp[100005];

int solve(int i, vector <int> &a, int &n, int &k){
    if(i >= n - 1) return 0;

    if(dp[i] != -1){
        return dp[i];
    }

    int ans = INT_MAX;

    for(int j = i + 1; j <= min(n - 1, i + k); ++j){
        ans = min(ans, abs(a[j] - a[i]) + solve(j, a, n, k));
    }

    return dp[i] = ans;
}

int main(){

    // fast();
    memset(dp, -1, sizeof(dp));
    
    int n, k;
    cin >> n >> k;

    vector <int> h(n);
    read(h, n);

    cout << solve(0, h, n, k);
    
    return 0;
}