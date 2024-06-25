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

    vector <ll> pre(n + 1, 0);
    for(ll i = 0; i < n; ++i){
    	pre[i + 1] = pre[i] + a[i];
    }

    // print(pre, i, n + 1);

    ll q;
    cin >> q;

    while(q--){
    	ll l, u;
    	cin >> l >> u;

    	ll r1 = upper_bound(pre.begin(), pre.end(), pre[l - 1] + u) - pre.begin();
    	ll r2 = r1 - 1;

    	// cout << r1 << " " << r2 << "\n";

    	if(r1 > n){
    		cout << n << " ";
    	}
    	else if(r2 < l){
    		cout << r1 << " ";
    	}
    	else{
    		ll a1 = pre[r1] - pre[l - 1];
    		ll a2 = pre[r2] - pre[l - 1];

    		ll l1 = u - a1 + 1;
    		ll l2 = u - a2 + 1;

    		ll ans1 = (a1 * (l1 + u)) / 2;
    		ll ans2 = (a2 * (l2 + u)) / 2;

    		if(ans1 > ans2){
    			cout << r1 << " ";
    		}
    		else{
    			cout << r2 << " ";
    		}
    		// cout << l1 << " " << l2 << " : " << a1 << " " << a2 << "  " << ans1 << " " << ans2 << "\n"; 
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