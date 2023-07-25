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

ll dp[10005][2][105];
// index, sum % d, 

ll solve(ll i, bool tight, ll sm, string &s, ll &n, ll &d){

    if(i == n){
        // cout << "Hello! " << sm << "\n";
        return (sm == 0);
    }

    if(dp[i][tight][sm] != -1){
        return dp[i][tight][sm];
    } 

    ll ans = 0;

    if(tight){
        for(ll j = '0'; j <= s[i]; ++j){
            if(j == s[i]){
                ans += solve(i + 1, tight, (sm + (j - '0')) % d, s, n, d);
            }
            else{
                ans += solve(i + 1, 0, (sm + (j - '0')) % d, s, n, d);
            }

            ans %= mod;
        }
    }
    else{
        for(ll j = '0'; j <= '9'; ++j){
            ans += solve(i + 1, 0, (sm + (j - '0')) % d, s, n, d);
            ans %= mod;
        }
    }

    return dp[i][tight][sm] = ans % mod;
}

int main(){

    // fast();
    memset(dp, -1, sizeof(dp));

    string s;
    cin >> s;

    ll d;
    cin >> d;

    ll n = s.size();

    ll ans =  (solve(0, 1, 0, s, n, d) - 1 + mod) % mod;
    cout << ans << "\n";
    
    
    return 0;
}