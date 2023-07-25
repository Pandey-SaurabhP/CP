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

ll getSquareRoot(ll x){

    ll l = 1;
    ll h = 10000000ll;

    ll ans = -1ll;

    while(l < h){
        ll mid = (l + h) / 2;

        if(mid * mid == x){
            return mid;
        }
        else if(mid * mid < x){
            ans = mid;
            l = mid + 1;
        }
        else{
            h = mid;
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

        if(x == 1){
            cout << -1 << "\n";
            continue;
        }

        ll s = getSquareRoot(x);

        // cout << s * s << "\n";

        if(s * s == x){
            --s;
        }

        if(x - (s * s) > 1000000){
            cout << s + 1 << " " << s << " " << x - ((s + 1) * s) << "\n";
        }
        else{
            cout << s << " " << s << " " << x - (s * s) << "\n";
        }
    }
    
    return 0;
}