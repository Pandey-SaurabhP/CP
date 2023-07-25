// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <ll> factorial(mxn);

ll fastPower(ll b, ll exp){

    ll ans = 1ll;

    while(exp){

        if(exp % 2ll == 1ll){
            ans = (ans * b);
            ans %= mod;
        }

        exp = exp >> 1ll;
        b *= b;

        b %= mod;
    }

    return ans % mod;
}

ll mmi(ll x){
    return fastPower(x, mod - 2ll) % mod;
}


ll npr(ll n, ll r){

    ll ans = factorial[n];
    ll den = factorial[n - r] * factorial[r];
    den %= mod;

    ans *= mmi(den);
    ans %= mod;

    return ans;
}

int main(){

    fast();

    factorial[0] = 1;
    for(ll i = 1; i < mxn; ++i){
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= mod;
    }

    // print(factorial, 10);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        for(ll i = 0; i < n; ++i) --a[i];

        ll ans = 0;

        for(ll i = 0; i < n; ++i){
            if(a[i] > i){
                continue;
            }

            // cout << i << " P " << a[i] << " " << npr(i, a[i]) << "   " << 2 << " " << n - i - 1 << " ";

            ans += (npr(i, a[i]) % mod * fastPower(2, n - i - 1) % mod) % mod;
            ans %= mod;
            // cout << ans << "\n";
        }

        cout << ans % mod << "\n";
    }
    
    return 0;
}