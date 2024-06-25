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
ll dp[51][51001];


void solve() {
 	ll n, k;
 	cin >> n >> k;

 	vector <pii> a(n);

 	ll mx = 0;

 	rep(i, 0, n){
 		cin >> a[i].ff >> a[i].ss;
 		mx = max(mx, a[i].ss);
 	}   

 	++mx;


 	for(ll i = 0; i < n; ++i){
 		for(ll j = 0; j < n * mx; ++j){
 			dp[i][j] = 1000000000000000000ll;
 		}
 	}

 	dp[0][0] = 0;
 	dp[0][a[0].ss] = (a[0].ff == 0? a[0].ff: INT_MAX);
 	// dp[0][a[0].ss] = a[0].ff;

 	for(ll i = 1; i < n; ++i){
 		dp[i][0] = 0;
 		for(ll j = 1; j < n * mx; ++j){
 			dp[i][j] = dp[i - 1][j];
 			if(j - a[i].ss >= 0){
 				ll sval = a[i].ff + dp[i - 1][j - a[i].ss];

 				if(sval <= i * k){
 					dp[i][j] = min(dp[i][j], sval);
 				}
 			}
 		}
 	}


 	// for(int i = 0; i < n; ++i){
 	// 	for(int j = 0; j < 20; ++j){
 	// 		if(dp[i][j] == INT_MAX){
 	// 			cout << "- ";
 	// 		}
 	// 		else{
 	// 			cout << dp[i][j] << " ";
 	// 		}
 	// 	}

 	// 	cout << "\n";
 	// }

 	ll ans = 0;
 	for(ll i = 0; i < n * mx; ++i){
 		if(dp[n - 1][i] <= (n - 1) * k){
 			ans = max(ans, i);
 		}
 	}

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