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

int solve(int i, vector <int> &a, int &n){
    if(i >= n - 1) return 0;

    if(dp[i] != -1){
        return dp[i];
    }

    if(i + 2 <= n - 1){
        return dp[i] = min(abs(a[i] - a[i + 1]) + solve(i + 1, a, n), abs(a[i] - a[i + 2]) + solve(i + 2, a, n));
    }
    else{
        return dp[i] = abs(a[i] - a[i + 1]) + solve(i + 1, a, n);
    }
}

int main(){

    // fast();
    memset(dp, -1, sizeof(dp));
    
    int n;
    cin >> n;

    vector <int> h(n);
    read(h, n);

    cout << solve(0, h, n);
    
    return 0;
}