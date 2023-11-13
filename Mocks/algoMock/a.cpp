
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

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

        ll xx, yy;
        xx = yy = 0;


        for(ll i = 0; i < 3; ++i){
            ll x, y;
            cin >> x >> y;

            xx += x;
            yy += y;

        }

        ll m;
        cin >> m;

        ll ans = INT_MAX;

        for(ll vx = -m; vx <= m; ++vx){
            // Set c, Get d
            ans = min(ans, abs(((xx - vx) * (xx - vx)) + (yy * yy)));
        }

        for(ll vy = -m; vy <= m; ++vy){
            ans = min(ans, abs((xx * xx) + ((yy - vy) * (yy - vy))));
        }

        cout << ans << "\n";
    }

    return 0;
}



