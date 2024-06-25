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
    ll n, m;
    cin >> n >> m;

    // for(ll a = 1ll; a <= n; ++a){

    // 	ll b = 

    // }

    for(ll ab = 2ll; ab <= n + m; ++ab){

    	ll cnt = 0;
    	for(ll a = 1ll; a <= n; ++a){
    		ll b = ab - a;

    		if(b < 1 || b > m){
    			continue;
    		}

    		if(ab % (b * __gcd(a, b)) == 0){
    			cout << a << " " << b << "\n";
    			++cnt;
    		}
    	}

    	cout << ab << " : " << cnt << "\n";
    }
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