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

ll getLCM(ll x, ll y){
	if(x > 1e9 || y > 1e9) return 1e10;

	ll gcd = __gcd(x, y);
	ll ans = (x * y) / gcd;

	if(ans > 1e9) return 1e10;
	return ans;
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    sort(a.begin(), a.end()); 

	ll lcm = 1;
	for(ll i = 0; i < n; ++i){
		lcm = getLCM(a[i], lcm);
	}

	if(lcm > 1e9 || binary_search(a.begin(), a.end(), lcm) == 0){
		cout << n << "\n";
		return;
	}

	ll mx = lcm;

	vector <ll> pl;
	for(ll i = 1; i * i <= mx; ++i){
		if(mx % i == 0){
			if(i == mx / i){
				pl.pb(i);
			}
			else{
				pl.pb(i); 
				pl.pb(mx / i);
			}
		}
	}

	ll ans = 0;

	for(auto it : pl){
		
		if(!binary_search(a.begin(), a.end(), it)){

			ll lcm = 1ll;
			ll cnt = 0;

			for(int i = 0; i < n; ++i){
				if(it % a[i] == 0){
					lcm = getLCM(lcm, a[i]);
					++cnt;
				}
			}

			// cout << it << " : " << lcm << " " << cnt << "\n";
			if(lcm == it){
				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << "\n";
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