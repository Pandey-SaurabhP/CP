#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

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
int a[101][101];

vector <int> getFactors(int x){

	vector <int> fct;

	for(int i = 1; i * i <= x; ++i){
		if(x % i == 0){
			if(i == x / i){
				fct.pb(i);
			}
			else{
				fct.pb(i);
				fct.pb(x / i);
			}
		}
	}

	return fct;
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		cin >> a[i][j];
    	}
    }

    int root = __gcd(a[0][0], a[n - 1][m - 1]);
    vector <int> fct = getFactors(root);

    int ans = 1;

	for(int i = 0; i < fct.size(); ++i){

		int x = i;
		int gcd = fct[i];

		bool dp[n + 1][m + 1];
		dp[0][0] = 1;

		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(i == 0 && j == 0){
					dp[i][j] = 1;
				}
				else if(i == 0){
					dp[i][j] = dp[i][j - 1] & (a[i][j] % gcd == 0);
				}
				else if(j == 0){
					dp[i][j] = dp[i - 1][j] & (a[i][j] % gcd == 0);
				}
				else{
					dp[i][j] = (dp[i][j - 1] & (a[i][j] % gcd == 0)) | dp[i - 1][j] & (a[i][j] % gcd == 0);
				}
			}
		}

		if(dp[n - 1][m - 1]){

			// cout << gcd << " ";
			ans = max(ans, gcd);
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