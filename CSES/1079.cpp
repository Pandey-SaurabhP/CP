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

vector <ll> fact(mxn);

ll fastPower(ll b, ll e, ll mod){
	ll ans = 1ll;

	while(e){

		if(e & 1){
			ans *= b;

			--e;
			ans %= mod;
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
	return fastPower(x, mod - 2, mod);
}


void solve() {
    ll a, b;
    cin >> a >> b;

    ll ans = fact[a];
    ll d1 = fact[b] * fact[a - b];
    d1 %= mod;

    ans *= mmi(d1);
    ans %= mod;

    cout << ans << "\n";
}

int main(){
    
    fast();

    fact[0] = 1ll;
    for(int i = 1; i < mxn; ++i){
    	fact[i] = i * fact[i - 1];
    	fact[i] %= mod;
    }



    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}