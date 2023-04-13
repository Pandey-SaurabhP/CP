// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

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

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        ll a, b, c, d;

        
        a = b = n;

        a |= (1ll << 46);
        b |= (1ll << 46);

        b |= (1ll << 38);

        c = (1ll << 35);

        d = c;
        d |= (1ll << 46);

        // cout << (((a & b) | c) ^ d) << "\n"; 

        cout << a << " " << b << " " << c << " " << d << "\n";
        
    }
    
    return 0;
}