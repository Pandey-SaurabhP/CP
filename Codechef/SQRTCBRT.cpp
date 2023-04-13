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

ll cubeRoot(ll x){
    if(x == 0 || x == 1){
        return x;
    }

    ll l = 1ll;
    ll r = 2000000;
    ll ans = 1ll;

    while(l < r){
        ll mid = (l + r) / 2;

        if((mid * mid * mid) <= x){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

    return ans;
}

int main(){

    // fast();

    ll t;
    cin >> t;

    while(t--){
        ll x;
        cin >> x;

        ll l = 1;
        ll h = 2000000000;

        ll ans = h;

        while(l < h){
            ll mid = (l + h) / 2;
            ll fx = mid - cubeRoot(mid * mid);

            // cout << mid << " : " << mid << " " << cubeRoot(mid * mid) << " : " << fx << "\n";

            if(fx >= x){
                ans = mid * mid;
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}