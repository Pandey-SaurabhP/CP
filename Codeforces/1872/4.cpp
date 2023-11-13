
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll getLCM(ll x, ll y){
    ll gcd = __gcd(x, y);
    return (1ll * x * y) / gcd;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, x, y;
        cin >> n >> x >> y;

        ll fctx = n / x;
        ll fcty = n / y;
        ll fctxy = n / getLCM(x, y);

        fctx -= fctxy;
        fcty -= fctxy;


        ll a1 = (fctx) * ((2 * n) - fctx + 1); a1 /= 2;
        ll a2 = fcty * (fcty + 1); a2 /= 2;

        cout << a1 - a2 << "\n";


    }

    return 0;
}



