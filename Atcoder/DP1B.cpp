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

    vector <int> h(n);
    read(h, n);

    vector <int> dp(n + 1);

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    
    for(int i = 2; i < n; ++i){
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(abs(h[i] - h[i - 2])));
    }

    cout << dp[n - 1];
    
    return 0;
}