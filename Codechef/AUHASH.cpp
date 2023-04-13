// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll dp[55][55][2005];
ll solve(ll mx, ll l, ll sm){

    if(sm < 0) return 0;

    if(l == 0){
        if(sm == 0) return 1;
        return 0;
    }

    if(dp[mx][l][sm] != -1){
        return dp[mx][l][sm];
    }

    ll ans = 0;

    for(ll i = mx + 1; i <= 52; ++i){
        ans += solve(i, l - 1, sm - i);
    }

    return dp[mx][l][sm] = ans;
}

int main(){

    fast();

    ll t;
    cin >> t;

    ll cnt = 1;

    while(t--){

        for(ll i = 0; i < 55; ++i){
            for(ll j = 0; j < 55; ++j){
                for(ll k = 0; k < 2005; ++k){
                    dp[i][j][k] = -1;
                }
            }
        }

        ll l, s;
        cin >> l >> s;

        if(l > 52 || s > 1378){
			cout << "Case " << cnt << ": " << 0 << "\n";
			++cnt;
			continue;
		}

		cout << "Case " << cnt << ": " << solve(0, l, s) << "\n";
		++cnt;
    }
    
    return 0;
}
