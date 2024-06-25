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

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

bool larger = 0;

ll fastPower(ll b, ll e, ll mod){
	ll ans = 1ll;

	while(e){

		if(e & 1){
			ans *= b;

			if(ans >= mod){
				larger = 1;
			}

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

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;


    ll m1 = 1e9 + 7;
    ll m2 = 1e9 + 6;

    ll p1 = fastPower(b, c, m2);
    ll p2 = fastPower(a, p1, m1);

    cout << p2 << "\n";
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