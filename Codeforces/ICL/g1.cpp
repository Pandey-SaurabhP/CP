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

// Read and Print
#define read(a, i, n) for(ll i = 0ll; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0ll; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 998244353;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0ll); cout.tie(0ll);
}

// Solve

vector <ll> ans(1005, -1ll);

ll gpower(ll b, ll e){
	ll a = 1ll;

	b %= mod;
	e %= mod;

	while(e){
		if(e & 1ll){
			a *= b;
			a %= mod;
			--e;
		}
		else{
			b *= b;
			b %= mod;
			e >>= 1ll;
		}
	}

	return a % mod;
}

ll mmi(ll x){
	ll ans = gpower(x, mod - 2ll);
	return ans % mod;
}

vector <ll> factorial(1005);

void build(){
	ll ans = 1ll;
	for(ll i = 1ll; i < 1005ll; ++i){
		ans *= i;
		ans %= mod;
		factorial[i] = ans;
	}
}

ll ncr2(ll n, ll r){

	ll num = factorial[n];
	num *= mmi(factorial[n - r]);
	num %= mod;
	num *= mmi(factorial[r]);
	num %= mod;
	return num;
}

void compute() {

    ans[0ll] = 0ll;
    ans[1ll] = 1ll;
    ans[2ll] = 1ll;

    for(ll i = 3ll; i < 1005ll; ++i){

    	ll rem = 0ll;

    	for(ll k = 1ll; k <= i - 1ll; ++k){

    		ll a1 = (((((i - k + mod) % mod) * ((i - k - 1 + mod) % mod)) % mod) * mmi(2ll)) % mod;

    		ll a2 = ((k % mod) * (gpower(2ll, a1) % mod)) % mod;

    		ll a3 = (a2 * ans[k]) % mod;

    		ll a4 = ((ncr2(i, k) % mod) * (a3 % mod)) % mod;

    		rem += a4;
    		rem %= mod;
    	}

    	rem *= mmi(i);
    	rem %= mod;

    	ans[i] = (gpower(2ll, ncr2(i, 2ll)) % mod) - rem + mod;
    	ans[i] %= mod;
    }
}

int main(){
    fast();
    build();
    compute();

    int t;
    cin >> t;

    while(t--){
    	int n;
    	cin >> n;

    	cout << (ans[n] + 1) % mod << "\n";
    }

    return 0;
}