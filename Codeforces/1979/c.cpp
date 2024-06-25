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

ll getLCM(ll x, ll y){

	if(x > 1e9 || y > 1e9) return 1e10;
 
	ll gcd = __gcd(x, y);

	ll res =  (x * y) / gcd;

	if(res > 1e9){
		return 1e10;
	}

	return res;
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> ans(n, -1);

    bool ok = 1;
    ll val = 0;


    for(ll i = 0; i < n; ++i){

    	vector <ll> tmp;

    	for(ll j = 1; j <= a[i]; ++j){
    		if(a[i] % j == 0){
	    		tmp.pb(j);
    		}
    	}

    	sort(tmp.rbegin(), tmp.rend());

    	vector <ll> b = a;

    	for(ll j = 0; j < n; ++j){
    		for(auto it : tmp){
    			if(b[j] % it == 0){
    				b[j] /= it;
    			}
    		}
    	}

    	print(b, j, n);

    	ll lcm = 1;

    	for(ll j = 0; j < n; ++j){
    		lcm = getLCM(b[j], lcm);
    	}

    	ans[i] = lcm;
    	val += ans[i];
    }

    print(ans, i, n);
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