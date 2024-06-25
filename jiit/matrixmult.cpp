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

ll slv(ll x, ll y, vector <ll> &a, ll &n){

	if(x == y) return 0;

	ll ans = INT_MAX;

	for(ll k = x; k < y; ++k){
		ans = min(ans, slv(x, k, a, n) + slv(k + 1, y, a, n) + a[x - 1] * a[k] * a[y]);
	}

	return ans;
}

ll slv2(vector <ll> &a, ll &n){

	ll dp[n][n];
	memset(dp, 0, sizeof(dp));

	for(int l = 1; l < n; ++l){
		
		int x = 1;
		int y = 1 + l;

		while(x < n && y < n){

			dp[x][y] = INT_MAX;
			for(int k = x; k < y; ++k){
				dp[x][y] = min(dp[x][y], 
					dp[x][k] + dp[k + 1][y] + a[x - 1] * a[k] * a[y]);
			}

			++x, ++y;
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << dp[i][j] << "\t"; 
		}
		cout << "\n";
	}

	return dp[1][n - 1];
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    cout << slv2(a, n);
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