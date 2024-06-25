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
    ll n, c;
    cin >> n >> c;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> b(n - 1);

    for(ll i = 1; i < n; ++i){
    	b[i - 1] = a[i];
    }
    sort(b.begin(), b.end());

    ll sm = accumulate(a.begin(), a.end(), 0ll);

    ll ans = 0;

    for(ll sz = 1; sz <= n - 1; ++sz){


    	for(ll i = 0; i < n - sz; ++i){

    		ll sm1 = 0;
    		for(ll j = i; j < i + sz; ++j){
    			sm1 += b[j];
    		}
    		ll sm2 = sm - sm1;

    		if((sm1 * sm2) <= c){
    			ans = max(ans, sz);
    		}

    		// cout << sz << " " << i << " " << i + sz << " : " << sm1 * sm2 << "\n"; 
    	}
    }

    cout << n - ans << "\n";
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