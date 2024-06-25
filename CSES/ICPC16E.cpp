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

ll fastPower(ll b, ll e, ll m = mod){
	ll ans = 1ll;

	while(e){
		if(e & 1ll){
			ans *= b;
			ans %= mod;
			--e;
		}
		else{
			b *= b;
			b %= mod;
			e >>= 1ll;
		}
	}

	return ans;
}

ll mmi(ll x){
	return fastPower(x, mod - 2ll);
}

void solve() {
    ll n, c;
    cin >> n >> c;

    ll ans = 0ll;

    ll p = fastPower(c, n); p %= mod;
    p = fastPower(p, n); p %= mod;

    ll x1 = fastPower(p, 5ll); x1 %= mod;
    ans += x1; x1 %= mod;

    x1 = fastPower(p, 2ll); x1 %= mod;
    ans += x1; ans %= mod;

    x1 = fastPower(p, 2ll); x1 %= mod;
    ans += x1; ans %= mod;

    x1 = fastPower(p, 3ll); x1 %= mod;
    ans += x1; x1 %= mod;

    ans *= mmi(4ll); ans %= mod;

    cout << ans << "\n";
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