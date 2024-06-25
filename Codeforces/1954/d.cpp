#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
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
const ll mod = 998244353ll;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll dp[5005][5005];

ll slv(ll i, ll target, vector <ll> &a, ll &n){

	if(target < 0ll) return 0;
	if(i == n){
		return (target == 0ll);
	}

	if(dp[i][target] != -1){
		return dp[i][target];
	}

	ll a1 = slv(i + 1, target - a[i], a, n) % mod;
	ll a2 = slv(i + 1, target, a, n) % mod;


	return dp[i][target] = (a1 + a2) % mod;
}

void solve() {
	memset(dp, -1, sizeof(dp));

    ll n;
    cin >> n;


    vector <ll> a(n);
    read(a, i, n);

    sort(a.rbegin(), a.rend());

    ll sm = accumulate(a.begin(), a.end(), 0ll);

    ll ans = 0ll;

    for(ll i = 0; i < n; ++i){ // index

    	for(ll j = 0; j < 5001; ++j){ // Sum

    		ll cont;
    		ll comb = slv(i + 1, j, a, n) % mod;

    		if(a[i] >= j){
    			cont = a[i];
    		}
    		else{
    			cont = (j + a[i] + 1) / 2ll;
    		}

    		cont %= mod;


    		ans += (cont * comb);
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