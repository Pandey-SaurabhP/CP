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

ld dp[101][601];

ld solve(ll i, ll sum, ll n, ll a, ll b) {
    
    if(i == n){
    	return (sum >= a && sum <= b? 1.0: 0.0);
    }	

    if(dp[i][sum] != -1.0) return ld(dp[i][sum]);

    ld ans = 0.0;

    for(ll j = 1; j <= 6; ++j){
    	ans += ld(solve(i + 1, sum + j, n, a, b));
    }

    return dp[i][sum] = ld(ans / 6.0);
}

int main(){
    
    fast();

    rep(i, 0, 101){
    	rep(j, 0, 601){
    		dp[i][j] = -1.0;
    	}
    }

    ll n, a, b;
    cin >> n >> a >> b;

    ld inRange = solve(0, 0, n, a, b);
    cout << fixed << setprecision(6) << inRange << "\n";

    return 0;
}