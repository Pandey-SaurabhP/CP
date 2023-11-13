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

int main(){

    // fast();

    ll t;
    cin >> t;

    while(t--){
        ll x;
        cin >> x;

        ll lo = 0;
        ll hi = 3e9;

        ll ans = 1;
        ll a1 = 1;

        while(lo < hi){
            ll mid = (lo + hi) / 2;
            ll n = (mid * (mid - 1)) / 2;

//            cout << mid << "\n";

            if(n <= x){
                ans = mid;
                a1 = n;
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }

        cout << ans + (x - a1) << "\n";
    }

    return 0;
}
