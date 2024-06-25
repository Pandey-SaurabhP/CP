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
	ll ans = 1ll;

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

	return ans % mod;
}

ll dsum(ll x){
	ll ans = 0;

	while(x){
		ans += (x % 10);
		x /= 10;
	}

	return ans;
}

ll qans(ll x, ll k){
	
	if(x == 0){
		return 1;
	}	

	ll ulim = ((10 + k - 1) / k) - 1;
	ll ans = fastPower(ulim + 1, x);

	return ans;
}

void solve() {
    ll l, r, k;
    cin >> l >> r >> k;

    // cout << ans.size() << " -> ";
    // print(ans, i, ans.size());

    ll fans = (qans(r, k) - qans(l, k) + mod) % mod;

    cout << fans << "\n";

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