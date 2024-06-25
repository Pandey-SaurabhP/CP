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
    ll n, k, q;
    cin >> n >> k >> q;

    vector <ll> a, b;
    a.pb(0);
    b.pb(0);

    rep(i, 0, k){
    	ll x; cin >> x; a.pb(x);
    }

    rep(i, 0, k){
    	ll x; cin >> x; b.pb(x);
    }

// 0 4 5 8 11
// 0 3 4 5 8

    // 0 4 10
    // 0 4 7
    for(ll i = 0; i < q; ++i){
    	ll x;
    	cin >> x;

    	ll ub = upper_bound(a.begin(), a.end(), x) - a.begin();
    	--ub; // This is the index of last visit less than the current element

    	if(a[ub] == x){
    		cout << b[ub] << " ";
    	}
    	else{
    		double tm = 1.0 * (b[ub + 1] - b[ub]) / (a[ub + 1] - a[ub]);
    		double ans = (x - a[ub]) * tm;
    		ans += b[ub];
    		ll ansi = ans;

    		cout << ansi << " ";
    	}
    }

    cout << "\n";
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