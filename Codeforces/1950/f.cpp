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
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll justSmaller(ll x){

	ll lvl = 0;

	for(ll i = 1; 1; i <<= 1){
		if((i - 1) >= x){
			return lvl;
		}
		++lvl;
	}

	return -1;
}

ll getPower(ll b, ll e){
	ll ans = 1;

	while(e){
		if(e & 1){
			ans *= b;
			--e;
		}
		else{
			b *= b;
			e >>= 1;
		}

		b %= mod;
		ans %= mod;
	}

	return ans;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    if(a + 1 != c){
    	cout << -1 << "\n";
    }
    else{
    	ll sm = justSmaller(a);
    	ll pw = getPower(2, sm) - 1;
    	b -= (pw - a);

    	sm += (b + c - 1) / c;

    	cout << sm << "\n";
    }
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