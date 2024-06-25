#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n);
    vector <ll> b(m);
    vector <ll> c(k);

    read(a, i, n);
    read(b, i, m);
    read(c, i, k);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll mxDiff = a[1] - a[0];
    ll mxi = 1;

    for(ll i = 1; i < n; ++i){
        if(abs(a[i] - a[i - 1]) > mxDiff){
            mxDiff = a[i] - a[i - 1];
            mxi = i;
        }
    }

    ll old = mxDiff;

    ll req = (a[mxi] + a[mxi - 1]) / 2;

    // cout << req << "\n";

    for(ll i = 0; i < m; ++i){

        ll up = upper_bound(c.begin(), c.end(), req - b[i]) - c.begin();
        ll lo = up - 1;

        // cout << b[i] << " : ";

        if(up < k){
            // cout << c[up] << " ";
            ll cDiff = (b[i] + c[up]);
            // cout << abs(a[mxi] - cDiff) << " ";

            if(max(abs(a[mxi] - cDiff), abs(a[mxi - 1] - cDiff)) < mxDiff){
                // cout << "Changing ";
                mxDiff = max(abs(a[mxi] - cDiff), abs(a[mxi - 1] - cDiff));
            }
        }

        if(lo >= 0){
            // cout << c[lo] << " ";
            ll cDiff = (b[i] + c[lo]);
            // cout << abs(cDiff - a[mxi]) << " ";

            if(max(abs(a[mxi] - cDiff), abs(a[mxi - 1] - cDiff)) < mxDiff){
                // cout << "Changing ";
                mxDiff = max(abs(a[mxi] - cDiff), abs(a[mxi - 1] - cDiff));
            }
        }

        // cout << mxDiff << "";

        // cout << "\n";
    }

    a.pb(a[mxi] - mxDiff);

    sort(a.begin(), a.end());

    ll ans = a[1] - a[0];

    // prll(a, i, n + 1);

    for(ll i = 1; i < n + 1; ++i){
        ans = max(ans, a[i] - a[i - 1]);
    }

    cout << min(ans, old) << "\n";
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