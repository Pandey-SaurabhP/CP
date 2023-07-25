// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 998244353;
const ll mxn = 1e6 + 5;

vector <ll> factorial(mxn);

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <ll> pc;
map <pair <ll, ll>, ll> dp;

ll solve(ll i, ll left, vector <ll> &a, ll &n){
    if(left < 0ll){
        return 0ll;
    }

    if(i == n){
        return (left == 0ll);
    }

    if(dp.count({i, left})){
        return dp[{i, left}];
    }

    ll ans = 0;

    for(ll j = 0ll; j <= a[i]; ++j){
        if(left - j >= 0ll){
            ans += factorial[j] * solve(i + 1, left - j, a, n);
            ans %= mod;
        }
        else break;
    }

    return dp[{i, left}] = ans % mod;
}

int main(){

    fast();

    factorial[0] = 1ll;

    for(ll i = 1; i < mxn; ++i){
        factorial[i] = (factorial[i - 1] * i) % mod;
    }

    ll t;
    cin >> t;

    while(t--){
        dp.clear();

        ll n, k;
        cin >> n >> k;

        vector <ll> a(k);
        read(a, k);

        vector <ll> b(k);
        
        for(ll i = 0; i < k; ++i){
            b[i] = (a[i] - i - 1);
        }

        cout << solve(0ll, n - k, b, k) << "\n";
    }
    
    return 0;
}