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

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> g(n);

    for(ll i = 1; i < n; ++i){
    	g[i] = __gcd(a[i - 1], a[i]);
    }

    g.pb(INT_MAX);

    // print(g, i, n + 1);

    vector <ll> ff(n + 1, 1), fb(n + 1, 1);

    for(ll i = 1; i <= n; ++i){
    	ff[i] = (g[i] >= g[i - 1]) & ff[i - 1];
    }

    for(ll i = n - 1; i >= 0; --i){
    	fb[i] = (g[i] <= g[i + 1]) & fb[i + 1];
    }

    // print(ff, i, n + 1);
    // print(fb, i, n + 1);


    bool ok = 0;

    for(ll i = 0; i < n; ++i){
    	// Remove ith element

    	if(i == 0 || i == n - 1){
    		if(i == 0){
    			if(fb[i + 2]){
    				ok = 1;
    				break;
    			}	
    		}
    		if(i == n - 1){
    			if(ff[i - 1]){
    				ok = 1;
    				break;
    			}
    		}
    	}
    	else{
    		// Skip ith element
    		ll ngcd = __gcd(a[i - 1], a[i + 1]);
    		if(ngcd >= g[i - 1] && ngcd <= g[i + 2] && ff[i - 1] && fb[i + 2]){
    			ok = 1;
    			// cout << i << "\n";
    			break;
    		}
    	}
    }

    if(ok) cout << "YES\n";
    else cout << "NO\n";

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