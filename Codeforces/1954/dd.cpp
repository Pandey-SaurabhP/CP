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
const ll mod = 998244353;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void cntComb(vector<ll> &a, ll &n) {

    for (ll i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    for (ll i = n - 1; i >= 0; --i) {
        for (ll j = 0; j <= 5001; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (j - a[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i + 1][j - a[i]]) % mod;
            }
        }
    }
}

void solve() {
	memset(dp, -1ll, sizeof(dp));
    
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    sort(a.rbegin(), a.rend());

    ll sm = accumulate(a.begin(), a.end(), 0ll);
    ll ans = 0ll;

    rep(i, 0, n){
    	rep(j, 0, sm + 1){
    		cntComb(i + 1, j, a, n);
    	}
    }

    rep(i, 0, n + 1){
        rep(j, 0, sm + 1){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    rep(i, 0, n){
    	rep(j, 0, sm + 1){
    			
    		ll combinations = cntComb(i + 1, j, a, n);
    		ll cnt;

    		if(a[i] >= j){
    			cnt = a[i];
    		}
    		else{
    			cnt = (j + a[i] + 1ll) / 2ll;
    		}

    		ans += (cnt * combinations) % mod;
    		ans %= mod;
    	}
    }

    cout << ans << "\n";
}

int main(){
    
    fast();
    solve();

    return 0;
}