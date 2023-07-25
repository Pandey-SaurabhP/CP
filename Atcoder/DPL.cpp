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

ll dp[3003][3003];

ll solve(ll s, ll e, bool turn, vector <ll> &a){

    if(s > e){
        return 0;
    }

    if(dp[s][e] != INT_MIN){
        return dp[s][e];
    }

    if(turn == 0){ // Taro
        ll s1 = a[s] + solve(s + 1, e, turn ^ 1, a);
        ll s2 = a[e] + solve(s, e - 1, turn ^ 1, a);

        return dp[s][e] = max(s1, s2);
    }
    else{          // Jiro
        ll s1 = solve(s + 1, e, turn ^ 1, a) - a[s];
        ll s2 = solve(s, e - 1, turn ^ 1, a) - a[e];

        return dp[s][e] = min(s1, s2);
    }
}

int main(){

    // fast();

    for(int i = 0; i < 3003; ++i){
        for(int j = 0; j < 3003; ++j){
            dp[i][j] = INT_MIN;
        }
    }

    for(int i = 0; i < 3003; +
+i)

    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, n);

    cout << solve(0, n - 1, 0, a);
    
    return 0;
}