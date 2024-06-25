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

bool check(ll x, ll y, ll n){

	ll cval = (x * x) + (y * y);
	ll lim = (n + 1) * (n + 1);

	if(cval < lim){
		return 1;
	}
	return 0;
}

bool check2(ll x, ll y, ll n){

	ll cval = (x * x) + (y * y);
	ll lim = n * n;

	if(cval >= lim){
		return 1;
	}
	return 0;
}


void solve() {
    ll n;
    cin >> n;

    ll ans = 0;

    for(ll i = 0; i <= n; ++i){

    	ll hiLim = 0;
    	ll lo = 0, hi = n;
	    while(lo <= hi){
	    	ll mid = (lo + hi) >> 1;

	    	if(check(i, mid, n)){
	    		hiLim = mid;
	    		lo = mid + 1;
	    	}
	    	else{
	    		hi = mid - 1;
	    	}
	    }

	    ll loLim = INT_MAX;
	    lo = 0, hi = n;
	    while(lo <= hi){
	    	ll mid = (lo + hi) >> 1;

	    	if(check2(i, mid, n)){
	    		loLim = mid;
	    		hi = mid - 1;
	    	}
	    	else{
	    		lo = mid + 1;
	    	}
	    }

	    ll cans = (hiLim >= loLim? (hiLim - loLim + 1): 0);
	    ans += cans;

	    // cout << i << " : " << loLim << " " << hiLim << "\n"; 
	}

	cout << 4 * ans - 4 << "\n";
    
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