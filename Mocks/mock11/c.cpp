#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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

ll a[1001][1001];
ll dp[1001][1001][5];

ll n, m;

ll solve(ll x, ll y, ll sz){
	if(dp[x][y][sz] != -1){
		return dp[x][y][sz];
	}


	ll ans = 0;
	bool okToGo = 0;

	if(x - 1 >= 0 && a[x - 1][y] - a[x][y] == 1){

		ans += solve(x - 1, y, min(sz + 1, 4ll));	
		ans %= mod;
		okToGo = 1;
	}
	if(x + 1 < n && a[x + 1][y] - a[x][y] == 1){

		ans += solve(x + 1, y, min(sz + 1, 4ll));
		ans %= mod;
		okToGo = 1;
	}
	if(y - 1 >= 0 && a[x][y - 1] - a[x][y] == 1){
		ans += solve(x, y - 1, min(sz + 1, 4ll));
		ans %= mod;
		okToGo = 1;
	}
	if(y + 1 < m && a[x][y + 1] - a[x][y] == 1){
		ans += solve(x, y + 1, min(sz + 1, 4ll));
		ans %= mod;
		okToGo = 1;
	}

	if(!okToGo){
		return (sz >= 4);
	}


	return dp[x][y][sz] = ans % mod;

}

void solve() {
	memset(dp, -1, sizeof(dp));
    cin >> n >> m;

    for(ll i = 0; i < n; ++i){
    	read(a[i], j, m);
    }

    ll ans = 0;

    for(ll i = 0; i < n; ++i){
    	for(ll j = 0; j < m; ++j){
    		if(dp[i][j][0] == -1 && dp[i][j][1] == -1 && dp[i][j][2] == -1 && dp[i][j][3] == -1 && dp[i][j][4] == -1){
    			ll l, r, u, d;
    			l = r = u = d = 100000000000000ll;

    			if(i - 1 >= 0 ){
    				u = a[i - 1][j];
    			}
    			if(i + 1 < n){
    				d = a[i + 1][j];
    			}
    			if(j - 1 >= 0){
    				l = a[i][j - 1];
    			}
    			if(j + 1 < m){
    				r = a[i][j + 1];
    			}


    			if(a[i][j] - l != 1 && a[i][j] - r != 1 && a[i][j] - u != 1 && a[i][j] - d != 1){
    				ans += solve(i, j, 1);
    				ans %= mod;
    			}
    		}
    	}
    }

    cout << ans;
}

int main(){
    
    fast();
    solve();

    return 0;
}