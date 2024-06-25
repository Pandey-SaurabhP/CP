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

ll dp[105][2][1001];
ll slv(ll c, bool longd, ll n, vector <ll> &a, vector <ll> &b){


	if(n == 0){
		return 1;
	}

	if(dp[c][longd][n] != -1){
		return dp[c][longd][n];
	}

	ll ans = 0;

	if(c != 104){
		// First step

		if(b[c] > 0){
			ans += (b[c] * slv(104, 1, n, a, b)) % mod;
		}
		if(a[c] > 0){
			ans += (a[c] * slv(104, 0, n, a, b)) % mod;
		}
		ans %= mod;
	}
	else{

		// Second step

		for(ll i = 0; i < a.size(); ++i){
			if(!longd && b[i] > 0){
				ans += (b[i] * slv(i, 0, n - 1, a, b)) % mod;
			}
			if(a[i] > 0){
				ans += (a[i] * slv(i, 0, n - 1, a, b)) % mod;
			}
			ans %= mod;
		}
	}

	return dp[c][longd][n] = ans % mod;

}

void solve() {
	memset(dp, -1, sizeof(dp));

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n), b(n);
    read(a, i, n);
    read(b, i, n);


    ll ans = slv(0, 0, m, a, b);
    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}