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

void solve() {
    ll n, k;
    cin >> n >> k;

    vector <ll> fct;

    for(ll i = 1; i * i <= n; ++i){
    	if(n % i == 0){
			fct.pb(i);
			fct.pb(n / i);
    	}
    }

    sort(fct.begin(), fct.end());

    ll ans = 1;

    for(auto it : fct){
    	
		ll left = n - (it * k);

		if(left < 0) break;

		if(left % it == 0){
			ans = max(it, ans);
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