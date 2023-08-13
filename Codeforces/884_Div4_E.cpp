#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        ll a[n];
        for(ll i = 0; i < n; ++i){
            cin >> a[i];
        }

        ll lo = 0ll;
        ll hi = 1e9 + 5;

        ll ans = -1;

        while(lo <= hi){

            ll mid = (lo + hi) / 2ll; // = w
            ll tmp = k;

            for(ll i = 0; i < n; ++i){
                tmp -= 1ll * ((2 * mid) + a[i]) * ((2 * mid) + a[i]);

                if(tmp < 0ll) break;
            }

            if(tmp == 0){
                ans = mid;
                break;
            }
            else if(tmp > 0){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }

        cout << ans << "\n";
    }
    
    return 0;
}