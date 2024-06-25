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
    ll l, r;
    cin >> l >> r;

    vector <pii> ans;

    while(l != r){
    	// Find max power of 2 that divides l

    	for(ll i = 60ll; i >= 0ll; --i){
    		if(l % (1ll << i) == 0ll){
    			ll x = (1ll << i) * ((l / (1ll << i)) + 1ll);

    			if(x > r){
    				continue;
    			}
    			else{
    				ans.pb({l, x});
    				l = x;
    				break;
    			}
    		}
    	}


    }

    cout << ans.size() << "\n";
    for(auto it : ans){
    	cout << it.ff << " " << it.ss << "\n";
    }
}

int main(){
    
    // fast();

    solve();

    return 0;
}