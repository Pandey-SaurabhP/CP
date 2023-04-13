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

ll getGCD(ll x, ll y){
    if(y == 0){
        return x;
    }

    return getGCD(y, x % y);
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll x, y;
        cin >> x >> y;

        ll gcd = getGCD(x, y);

        ll tx = x / gcd;

        while(((tx - 1ll) * y) <= x){
            tx *= 2ll;
        }

        --tx;

        ll n = (tx * y) - x;

        cout << n << "\n";
    }
    
    return 0;
}