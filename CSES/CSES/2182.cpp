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
 
ll cnt(vector <pii> a){
	ll ans = a[0].ss + 1;
	ll n = a.size();
 
	rep(i, 1, n){
		ans *= (a[i].ss + 1);
		ans %= mod;
	}
 
	return ans;
}
 
ll fastPower(ll b, ll e, ll m = mod){
 
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
	return fastPower(x, mod - 2);
}
 
ll gpSum(ll a, ll n){
 
	ll num = fastPower(a, n + 1);
	num %= mod;
 
	--num, num += mod, num %= mod;
 
	num *= mmi(a - 1);
	num %= mod;
 
	return num;
}
 
ll sm(vector <pii> a){
 
	ll ans = 1;
	ll n = a.size();
 
	rep(i, 0, n){
		ans *= gpSum(a[i].ff, a[i].ss);
		ans %= mod;
	}
 
	return ans;
}
 
ll prod(ll x, ll c){
	ll pw = (c, mod, mod);
	pw *= mmi(2ll);

	return fastPower(x, pw) % mod;
}
 
void solve() {
    	
	ll n;
	cin >> n;
 
	vector <pii> a(n);
	rep(i, 0, n){
		cin >> a[i].ff >> a[i].ss;
	}

	ll x = 1;
	rep(i, 0, n){
		x *= fastPower(a[i].ff, a[i].ss);
		x %= mod;
	}
 
	cout << cnt(a) << " " << sm(a) << " " << prod(x, cnt(a)) << "\n";
}
 
int main(){
    
    fast();
    solve();
    return 0;
}