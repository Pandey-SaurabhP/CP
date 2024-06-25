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
const ll mod = 998244353ll;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

ll fastPower(ll b, ll e){
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

ll lcm(ll a, ll b){
	ll gcd = __gcd(a, b);

	a /= gcd;
	b /= gcd;

	return (a * b * gcd);
}

ll target;
map <ll, ll> tf;

map <pii, ll> dp;

ll slv(ll i, ll val, vector <ll> &b, ll &n){
	if(val > target) return 0ll;

	if(i == n){
		return (val == target);
	}

	if(dp.count({i, val})) return dp[{i, val}];


	if(target % b[i] == 0ll){
		// Pick or leave
		ll built = 1ll;

		for(auto it : tf){
			if(b[i] % it.ss == 0ll){
				built *= it.ss;
			}
		}

		ll a1 = slv(i + 1ll, lcm(val, built), b, n) % mod;
		ll a2 = slv(i + 1ll, val, b, n) % mod;

		return dp[{i, val}] = (a1 + a2) % mod;
	}
	else{
		// Leave
		return dp[{i, val}] = slv(i + 1ll, val, b, n) % mod;
	}
}

void pf(){

	ll tmp = target;

	while(target % 2ll == 0){
		tf[2ll]++;
		target >>= 1ll;
	}

	for(ll i = 3ll; i * i <= target; i += 2ll){

		if(target % i == 0ll){
			while(target % i == 0ll){
				tf[i]++;
				target /= i;
			}
		}
	}

	if(target > 1ll){
		tf[target]++;
	}

	for(auto it : tf){
		tf[it.ff] = fastPower(it.ff, it.ss);
	}

	target = tmp;
}

void solve() {
    ll n, t;
    cin >> n >> t;

    target = t;

    vector <ll> a(n);
    read(a, i, n);

    pf();

    cout << slv(0, 1, a, n);
}

int main(){
    
    // fast();

    solve();

    return 0;
}