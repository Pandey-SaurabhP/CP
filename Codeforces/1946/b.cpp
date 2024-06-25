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

ll mxs(vector <ll> &a){
	ll n = a.size();

	ll mxg = 0;
	ll mxe = 0;

	for(ll i = 0; i < n; ++i){
		mxe += a[i];

		if(mxg < mxe){
			mxg = mxe;
		}

		if(mxe < 0){
			mxe = 0;
		}
	}

	return mxg;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, i, n);


    ll sm = accumulate(a.begin(), a.end(), 0ll);

    ll res = sm % mod;
    res += mod;
    res %= mod;

    ll sum = mxs(a);

    // cout << sum << " ";

    for(ll i = 0; i < k; ++i){
    	
    	res += sum;
    	res %= mod;
    	res += mod;
    	res %= mod;


    	sum *= 2ll;
    	sum %= mod;

    }


    cout << res << "\n";
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