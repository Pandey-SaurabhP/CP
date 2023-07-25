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

bool isPerfectSquare(ll x)
{
    ll n = x;
    ll lo = 1;
    ll hi = x;

    while (hi - lo > 1) {
        ll mid = (hi + lo) / 2;
        if (x == 1) {
            return true;
        }
        else if (mid * mid == x) {
            return true;
        }
        else if (mid * mid > x) {
            hi = mid - 1;
        }
        else if (mid * mid < x) {
            lo = mid + 1;
        }
    }
    if (lo * lo == x || hi * hi == x) {
        return 1;
    }
    return 0;
}

ll floorSqrt(ll x){
    // Base cases
    if (x == 0 || x == 1){
        return x;
    }
 
    ll start = 1, end = x / 2, ans;
    while (start <= end) {
        ll mid = (start + end) / 2;
 
        ll sqr = mid * mid;
        if (sqr == x){
            return mid;
        }
        if (sqr <= x){
            start = mid + 1;
            ans = mid;
        }
        else{
            end = mid - 1;
        }
    }
    return ans;
}

ll fastPower(ll b, ll e){

    ll ans = 1;

    while(e){

        if(e & 1){
            ans *= b;
            --e;
        }
        else{
            b *= b;
            e >>= 1;
        }
    }

    return ans;
}

bool oneDistance(ll n){
    ll d = (4 * n) - 3;

    if(!isPerfectSquare(d)){
        return 0;
    }

    ll sqr = floorSqrt(d);
    --sqr;

    if(sqr % 2 != 0) return 0;
    if(sqr / 2 <= 1) return 0;
    return 1;
}

ll lim = 1e18 + 9;

int main(){
    // fast();

    set <ll> vc;
    ll l2 = 1000000;

    for(ll b = 2; b < l2; ++b){

        ll ans = 1 + b;
        ll c = b * b;

        for(ll n = 3; n < 64; ++n){

            ans += c;

            if(ans <= lim){
                vc.insert(ans);
                c *= b;
            }  
            else break;
        }
    }

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if(oneDistance(n)){
            cout << "YES\n";
            continue;
        }

        if(vc.count(n)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}