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

int dp[25][25][25][25];

int slv(int a, int b, int c, int d){
	if(a < 0 || b < 0 || c < 0 || d < 0) return 0;
	if(a == 0 && b == 0 && c == 0 && d == 0){
		return 0;
	}

	if(dp[a][b][c][d] != -1){
		return dp[a][b][c][d];
	}

	int ans = 0;

	if((a & 1) && (b & 1) && (c & 1) && !(d & 1)){
		++ans;
	}

	if(!(a & 1) && !(b & 1) && !(c & 1) && !(d & 1)){
		++ans;
	}

	ans += max(max(slv(a - 1, b, c, d), slv(a, b - 1, c, d)),
			       max(slv(a, b, c - 1, d), slv(a, b, c, d - 1)));

		return dp[a][b][c][d] = ans;
}

int solve() {
	memset(dp, - 1,sizeof(dp));

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << slv(a, b, c, d) << "\n";
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