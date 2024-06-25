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

ll fastPower(ll a, ll n){
	ll ans = 1;
 
    while (n > 0) {
 
        ll last_bit = (n & 1ll);
        if (last_bit) {
            ans = ans * a;
        }
 
        a = a * a;
        n = n >> 1ll;
    }
 
    return ans;
}

void solve() {
    
    ll n;
    cin >> n;

    map <ll, ll> mp;

    for(ll i = 0; i < n; ++i){
    	ll type;
    	cin >> type;

    	if(type == 1){
    		ll x;
    		cin >> x;

    		mp[x]++;
    	}
    	else{
    		ll x;
    		cin >> x;

    		for(ll i = 29; i >= 0; --i){

    			ll p = fastPower(2, i);

				ll times = x / p;
				x -= min(times, mp[i]) * p;
    		}

    		if(x == 0){
    			cout << "YES\n";
    		}
    		else{
    			cout << "NO\n";
    		}
    	}
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}