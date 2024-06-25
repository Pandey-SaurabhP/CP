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

ll fact[mxn];

ll fastPower(ll b, ll e){
	ll ans = 1;

	while(e){
		if(e & 1){
			ans *= b;
			ans %= mod;
			--e;
		}
		else{
			b *= b;
			b %= mod;
			e >>= 1;
		}
	}

	return ans;
}

ll mmi(ll x){
	return fastPower(x, mod - 2);
}

ll getWays(ll x, ll y, ll tx, ll ty, ll n){
	ll a, b;

	if((n - y) >= 0 && (n - y) % 2 == 0){
		a = (n - y) / 2;
		b = n - a;

		// cout << "ab " << a << " " << b << "\n";

		ll ans = fact[a + b] % mod;
		ans *= mmi(fact[a]); ans %= mod;
		ans *= mmi(fact[b]); ans %= mod;

		return ans;
	}
	else{
		return -1;
	}
}

void solve() {
	fact[0] = 1; 
	for(ll i = 1; i < mxn; ++i){
		fact[i] = i * fact[i - 1];
		fact[i] %= mod;
	}
    
    ll n;
    cin >> n;

    string s;
    cin >> s;

    bool ok = 1;
    ll val = 0;

    for(auto it : s){
    	val += (it == '(');
    	val -= (it == ')');

    	if(val < 0) ok = 0;
    }

    if(!ok){
    	cout << 0;
    	return;
    }

    ll x = s.size();
    ll y = val;

    ll tx = n;
    ll ty = 0;

    ll left = n - s.size();

    ll ways1 = getWays(x, y, tx, ty, left);
    ll ways2 = getWays(x, -2 - y, tx, ty, left);

    if(ways1 == -1){
    	cout << 0 << "\n";
    	return;
    }

    ways1 -= ways2; ways1 += mod; ways1 %= mod;

    // cout << ways1 << " " << ways2 << " : " << ways1 - ways2 << "\n";
    cout << ways1 << "\n";

}

int main(){
    
    fast();

    solve();

    return 0;
}