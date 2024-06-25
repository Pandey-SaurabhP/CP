#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("avx2")

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
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll dp[(1 << 20) + 5];
ll id[21];

ll sm[(1 << 20) + 5];

inline ll distributed(ll src, ll x, ll n){
	
	memset(id, 0, sizeof(id));

	ll cnt = 0;

	for(ll i = 0; i < n; ++i){
		if(!((src >> i) & 1)){
			id[cnt] = i;
			++cnt;
		}
	}

	ll ans = 0;

	for(ll i = 0; (x >> i) > 0; ++i){
		if((x >> i) & 1){
			ans |= (1 << (id[i]));
		}
	}

	return ans;
}

inline bool disjoint(ll x, ll y){

	while(x | y){
		if((x & 1) && (y & 1)){
			return 0;
		}

		x >>= 1;
		y >>= 1;
	}

	return 1;
}

ll slv(ll done, vector <ll> &a, ll n, ll x){

	if(done == (1 << n) - 1) return 0;

	if(dp[done] != -1) return dp[done];

	ll ans = INT_MAX;

	ll freebits = 0;

	for(ll i = 0; i < n; ++i){
		if(!((done >> i) & 1)){
			freebits++;
		}
	}

	for(ll i = 1; i < (1 << freebits); ++i){

		ll nx = distributed(done, i, n);

		// cout << done << " " << i << " : " << nx << "\n";

		if(sm[nx] > x) continue;

		ans = min(ans, 1 + slv(done | nx, a, n, x));
	}

	return dp[done] = ans;
}

ll bu(vector <ll> &a, ll n, ll x){

	ll dpx[(1 << 20) + 5];

	dpx[0] = 0;

	for(ll i = 1; i < (1 << n); ++i){

		ll freebits = 0;

		for(ll j = 0; j < i; ++j){
			if(!((done >> j) & 1)){
				freebits++;
			}
		}

	}
}

void solve() {
	memset(dp, -1, sizeof(dp));

    ll n, x;
    cin >> n >> x;

    vector <ll> a(n);
    read(a, i, n);

    for(ll i = 0; i < (1 << n); ++i){

    	ll csum = 0;
    	for(ll j = 0; (i >> j) > 0; ++j){
    		if(i & (1 << j)){
    			csum += a[j];
    		}
    	}

    	sm[i] = csum;
    }

    // cout << distributed(4, 4, 4) << "\n";
    cout << slv(0, a, n, x) << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}