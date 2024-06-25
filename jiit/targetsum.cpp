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

int dp[105][10005];

ll topdown(ll i, ll t, vector <ll> &a, ll &n){

	if(i == n){
		return (t == 0? 0: INT_MAX);
	}

	if(dp[i][t] != -1) return dp[i][t];

	ll a1 = 1 + topdown(i + 1, t - a[i], a, n);
	ll a2 = topdown(i + 1, t, a, n);

	return dp[i][t] = min(a1, a2);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	
    ll n, t;
    cin >> n >> t;

    vector <ll> a(n);
    read(a, i, n);

    cout << topdown(0, t, a, n);
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