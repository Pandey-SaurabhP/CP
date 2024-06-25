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

	return ans % mod;
}

ll mmi(ll x){
	return fastPower(x, mod - 2) % mod;
}

void solve() {
    
    string s;
    cin >> s;

    ll n = s.size();

    ll hsh[n];
    ll mult = 1ll;

    for(ll i = 0ll; i < n; ++i){
    	hsh[i] = (i - 1 >= 0ll? hsh[i - 1]: 0ll) + ((s[i] - 'a') * mult);
    	hsh[i] %= mod;

    	mult *= 26ll;
    	mult %= mod;
    }


    vector <ll> ans;

    for(ll i = 0ll; i < n - 1ll; ++i){
    	ll fhash = hsh[i];
    	ll bhash = hsh[n - 1ll] - hsh[n - i - 2ll];

    	bhash %= mod;
    	bhash += mod;
    	bhash %= mod;

    	bhash *= mmi(fastPower(26ll, n - i - 1ll));
    	bhash %= mod;

    	if(fhash == bhash){
    		ans.pb(i + 1);
    	}
    }

    print(ans, i, ans.size());
}

int main(){
    
    fast();
    solve();

    return 0;
}