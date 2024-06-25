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

const ll inf = 1e18;

ll dp[300005][11];

ll slv(vector <ll> &a, ll i, ll n, ll k, ll sm){
	

	if(i >= n){
		// cout << i << " " << k << " : " << sm << "\n";
		return 0ll;
	}

	if(dp[i][k] != -1ll){
		return dp[i][k];
	}

	ll gans = inf;
	ll mn = a[i];
	ll sz = 0ll;

	for(ll j = i; j <= min(i + k, n - 1); ++j){

		mn = min(mn, a[j]);
		++sz;

		ll cans = (sz * mn) + slv(a, j + 1, n, k - sz + 1, sm + (sz * mn));
		gans = min(gans, cans);
	}

	return dp[i][k] = gans;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    for(ll i = 0; i <= n; ++i){
    	for(ll j = 0; j <= k; ++j){
    		dp[i][j] = -1ll;
    	}
    }

    vector <ll> a(n);
    read(a, i, n);

    cout << slv(a, 0ll, n, k, 0ll) << "\n";

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