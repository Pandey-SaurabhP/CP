#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll getK(ll g, ll n, ll m){

    ll lo = 0ll;
    ll hi = 2000005ll;
    ll ans = 0ll;

    while(lo <= hi){
        ll mid = (lo + hi) >> 1ll;

        ll res = g * ((g * mid) - 1);

        if(res > n){
            hi = mid - 1;
        }
        else{
            ans = mid;
            lo = mid + 1;
        }
    }

    return (g == 1? ans - 1ll: ans);
}



void solve() {
    ll n, m;
    cin >> n >> m;

    // for(ll a = 1ll; a <= n; ++a){

    //  ll b = 

    // }

    // ll cnt = 0;

    // for(ll ab = 2ll; ab <= n + m; ++ab){

    //     ll cnt = 0;
    //     for(ll a = 1ll; a <= n; ++a){
    //         ll b = ab - a;

    //         if(b < 1 || b > m){
    //             continue;
    //         }

    //         if(ab % (b * __gcd(a, b)) == 0){
    //             cout << a << " " << b << "\n";
    //             ++cnt;
    //         }
    //     }

    //     // cout << ab << " : " << cnt << "\n";
    // }

    // cout << "\n\n";


    ll cnt2 = 0ll;

    for(ll g = 1ll; g <= min(n, m); ++g){
        ll y = 1ll;

        // cnt2 += getK(g, n, m);

        // cout << g << " : " << getK(g, n, m) << "\n";

        for(ll k = 1; g * ((g * k) - 1) <= n; ++k){

            ll a = g * ((g * k) - 1);
            ll b = g;

            if(g == 1 && k == 1) continue;

            // cout << g << " " << y << " " << k << " : " << a << " " << b << "\n";
            ++cnt2;
        }

            // cout << g << " " << y << " : " << k << "\n";

            // cnt2 += k;
        
    }

    // for(ll y = 1ll; y <= m; ++y){

    //     for(ll g = 1ll; y * g <= n + m; ++g){

    //         // ++cnt2;

    //         for(ll k = 1ll; g * (y * (g * k - 1)) <= n; ++k){

    //             ll x = g * y * ((g * k) - 1);
    //             ll yy = g * y;

    //             if(x <= n && yy <= m){

    //                 cout << g << " " << y << " " << k << " : " << x << " " << yy << "\n";
    //                 ++cnt2;
    //             }
    //         }
    //     }
    // }

    cout << cnt2 << "\n";
    // cout << cnt << " " << cnt2 << "\n";
}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}