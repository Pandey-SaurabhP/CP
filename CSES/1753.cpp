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

ll getHash(string s){

	ll ans = 0;

	for(ll i = 0; i < s.size(); ++i){
		ans += fastPower(26, i) * (s[i] - 'a');
		ans %= mod;
	}

	return ans;
} 


void solve() {
    string s, p;
    cin >> s >> p;

    ll hp = getHash(p);

    vector <ll> hs(s.size());

    for(ll i = 0ll; i < p.size(); ++i){
    	if(i == 0ll){
    		hs[i] = s[i] - 'a';
     	}
     	else{
     		hs[i] = hs[i - 1] + (fastPower(26ll, i) * (s[i] - 'a')) % mod;
     		hs[i] %= mod;
     		hs[i] += mod;
     		hs[i] %= mod;
     	}
    }

    ll chash;
    ll ans = (hs[p.size() - 1] == hp);

    // cout << hs[0] << " " << hs[1] << "\n";

    for(ll i = p.size(); i < s.size(); ++i){
    	// cout << i << " : ";

    	ll chash = hs[i - 1] - (s[i - p.size()] - 'a');

    	chash += mod;
    	chash %= mod;

    	// cout << chash << " ";

    	chash *= mmi(26ll);
    	chash %= mod;

    	// cout << chash << " ";

    	chash += (fastPower(26ll, p.size() - 1) * (s[i] - 'a'));
    	chash %= mod;

    	hs[i] = chash;

    	// cout << chash << " " << hp << "\n";

    	ans += (chash == hp);
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}