// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll inf = INT_MAX;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    fast();

    ll t;
    cin >> t;

    ll T = t;
    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;

        vector <ll> a(n);
        vector <ll> b(m);

        read(a, n);
        read(b, m);

        ll ans = inf;

        ll As = accumulate(a.begin(), a.end(), 0ll);
        ll Bs = accumulate(b.begin(), b.end(), 0ll);

        if(m * As > n * Bs){
            cout << 0 << "\n";
            continue;
        }

        ll t1 = (m * As) - (n * Bs);
        ll tx = (k * m) - Bs;

        for(ll x = 0ll; x < 10 * m + 10 * n + 1; ++x){

            ll tmp = tx;
            tx *= x;

            ll den = ((n - As) + ((1ll - k) * x));
            if(den == 0){
                continue;
            }

            ll y = (t1 + tx) + den - 1ll;
            y /= den;

            if(y <= 0ll) break;

            ll lc = x + y;
            ans = min(ans, lc);

            tx = tmp;
        }

        // ll ty = (As - n);
        // for(ll y = 0ll; T * y < 10ll * m + 10ll * n + 1ll; ++y){
        //     ll tmp = ty;

        //     ty *= y;

        //     ll den = (y + Bs - (k * m) - (k * y));
        //     if(den == 0ll) continue;

        //     ll x = (t1 + ty) + den - 1ll;
        //     x /= den;

        //     if(x <= 0ll) break;

        //     ll lc = x + y;
        //     ans = min(ans, lc);

        //     ty = tmp;
        // }

        if(ans == INT_MAX){
            cout << -1 << "\n";
        }
        else{
            cout << ans << "\n";
        }
        // cout << ans << "\n";

    }
    
    return 0;
}