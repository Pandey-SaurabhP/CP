// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 998244353;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll l, r;
        cin >> l >> r;

        ll cnt = 0;
        ll tmp = l;

        while(tmp <= r){
            tmp *= 2;
            ++cnt;
        }


        if(cnt <= 1){
            cout << 1 << " " << r - l + 1 << "\n";
        }
        else{

            ll ans = 0;

            ll threeTake = r / ((1 << (cnt - 2)) * 3);

            if(threeTake >= l) ans += max(((threeTake - l + 1) * cnt), 0ll);

            ans %= mod;

            ll twoTake = r / (1 << (cnt - 1));

            if(twoTake >= l) ans += (twoTake - max(threeTake, l - 1)) ;
            ans %= mod;

            cout << cnt << " " << ans << "\n";
        }
    }
    
    return 0;
}