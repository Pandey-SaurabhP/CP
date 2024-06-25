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
ll upperBound(ll x, ll n){

	ll ans = -1;

	ll r = 1;
	ll hi = n;

	while(r <= hi){
		ll mid = (r + hi) >> 1;

		if(n / mid >= x){
			r = mid + 1;
			ans = mid;
		}
		else{
			hi = mid - 1;
		}
	}

	return ans;
}

ll lowerBound(ll x, ll n){

	ll ans = -1;

	ll r = 1;
	ll hi = n;

	while(r <= hi){
		ll mid = (r + hi) >> 1;

		if(n / mid > x){
			r = mid + 1;
		}
		else{
			hi = mid - 1;
			ans = mid;
		}
	}

	return ans;
}

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
    ll n;
    cin >> n;

    ll rn = sqrt(n);

    ll ans = 0;

    ll ed = n;

    ll l, r;
    
    for(ll i = 1; i <= rn; ++i){

    	r = n / i;
    	l = n / (i + 1);


    	ll sum = 0ll;

    	sum += ((((r % mod) * ((r + 1) % mod)) % mod) * mmi(2ll)) % mod;
    	sum %= mod;
    	sum -= ((((l % mod) * ((l + 1) % mod)) % mod) * mmi(2ll)) % mod;
    	sum += mod; sum %= mod;
    	sum *= i; sum %= mod;
    	ans += sum; ans %= mod;

    	// cout << i << " : " << l << " " << r << " -> " << sum << "\n";
    	ed = min(ed, l);



    	// This much part will be equal
    }

    for(ll i = 1ll; i <= ed; ++i){
    	ans += (i * (n / i)) % mod;
    	ans %= mod;
    }

    cout << ans << "\n";

}

int main(){
    
    fast();

    solve();

    return 0;
}