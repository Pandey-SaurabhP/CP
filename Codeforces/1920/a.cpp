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
    ll n;
    cin >> n;

    ll lo = INT_MIN;
    ll hi = INT_MAX;

    set <ll> st;

    for(ll i = 0; i < n; ++i){
    	ll a, x;
    	cin >> a >> x;

    	if(a == 1){
    		lo = max(lo, x);
    	}
    	if(a == 2){
    		hi = min(hi, x);
    	}
    	if(a == 3){
    		st.insert(x);
    	}
    }

    ll cnt = 0;
    for(auto it : st){
    	if(it >= lo && it <= hi){
    		++cnt;
    	}
    }
    
    ll ans = max((hi - lo + 1) - cnt, 0ll);

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