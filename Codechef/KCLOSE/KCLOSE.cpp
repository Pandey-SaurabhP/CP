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
    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, i, n);

    sort(a.begin(), a.end());
    rep(i, 0, n) a[i] += ((a[n - 1] - a[i]) / k) * k;
    sort(a.begin(), a.end());

    // print(a, i, n);

    ll mn = a[0];
    ll mx = a[n - 1];
    ll ans = mx - mn;

    rep(i, 0, n){
    	a[i] += k;
    	if(i + 1 < n) mn = min(a[i + 1], a[0]);
    	else{
    		mn = a[0];
    	}
    	mx = max(mx, a[i]);
    	ans = min(ans, mx - mn);


    	// cout << mx << " " << mn << " : ";
    	// print(a, i, n);

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