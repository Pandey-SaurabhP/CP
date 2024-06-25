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

ll gcd(ll a, ll b){
	return (b == 0? a: gcd(b, a % b));
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> fct;

    for(ll i = 1; i * i <= n; ++i){
    	if(n % i == 0){
    		if(i == n / i){
    			fct.pb(i);
    		}
    		else{
    			fct.pb(i);
    			fct.pb(n / i);
    		}
    	}
    }

    sort(fct.begin(), fct.end());

    ll ans = 0;

    for(auto k : fct){
    	// Determined jump

    	if(k >= n){
    		++ans;
    		continue;
    	}

    	bool ok = 1;

    	ll g = -1;

    	for(ll j = 0; j < k; ++j){
	    	for(ll i = k + j; i < n; i += k){

	    		if(a[i] == a[i - k]) continue;

	    		if(g == -1){
	    			g = abs(a[i] - a[i - k]);
	    		}
	    		else g = gcd(abs(a[i] - a[i - k]), g);
	    	}
    	}

    	if(g == 1) ok = 0;

    	// cout << k << " : " << ok << "\n";
		if(ok) ++ans;    	
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