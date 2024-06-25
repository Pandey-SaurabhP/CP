#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll getPower(ll b, ll e){
	ll ans = 1ll;

	while(e){
		if(e & 1ll){
			ans *= b;
			ans %= mod;
		}

		e = e >> 1ll;
		b = b * b;
		b %= mod;
	}

	return ans % mod;
}

ll modInverse(ll a){
	return getPower(a, mod - 2);
}

void solve() {
 	int x;
 	cin >> x;

 	// if(x <= 9){
 	// 	ll ans = getPower(10, x);

 	// 	--ans;
 	// 	ans /= 3;

 	// 	cout << ans << "\n";
 	// 	return;
 	// }

 	ll pp = getPower(10, x);
 	pp--;

 	pp += mod;
 	pp %= mod;



 	pp *= 333333336ll;
 	pp %= mod;

 	cout << pp << "\n";
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