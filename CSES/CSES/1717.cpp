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

void solve() {
    
    ll n;
    cin >> n;

    vector <ll> fact(mxn, 1);
    for(ll i = 1; i < mxn; ++i){
    	fact[i] = fact[i - 1] * i;
    	fact[i] %= mod;
    }

    ll ans = 0;

    for(ll i = 0; i <= n; ++i){
    	ll xyz = (i % 2 == 0? 1: -1) * fact[n] * mmi(fact[i]); 
    	xyz %= mod; xyz += mod; xyz %= mod;
    	ans += xyz; ans %= mod;
    }

    cout << ans;
}

int main(){
    
    fast();
    solve();

    return 0;
}