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
const ll mxn = 3e4 + 5;
const ll mod = 1e9 + 7;
const ll inf = 1e14;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <ll> a(mxn);
vector <pair <ll, pii>> b(1001);
ll n, m;

ll dp[1005][30005];
ll pre[1005][30005];


ll slv(ll i, ll done){ // Moving on b[i]

	if(i == m){
		return 0;
	}

	if(done + b[i].ss.ff > n) return inf;
	if(dp[i][done] != -1) return dp[i][done];

// done + b[i].ss.ff can go to -1. handle that
	ll cost = pre[i][done + b[i].ss.ff - 1] - (done - 1 >= 0? pre[i][done - 1]: 0);
	// cout << done << " " << done + b[i].ss.ff << " : " << cost << "\n";

	ll a1 = cost + slv(i + 1, done + b[i].ss.ff);

	// These elements are optional
	for(ll j = done + b[i].ss.ff; j < min(done + b[i].ss.ss, n); ++j){

		cost = pre[i][j] - (done - 1 >= 0? pre[i][done - 1]: 0);
		a1 = min(a1, cost + slv(i + 1, j + 1));
	}

	return dp[i][done] = a1;
}

void solve() {
	memset(dp, -1, sizeof(dp));
    
    cin >> n >> m;

    read(a, i, n);

    ll mnx, mxx;
    mnx = mxx = 0;

    for(ll i = 0; i < m; ++i){
    	ll u, v, w;
    	cin >> u >> v >> w;

    	mnx += v;
    	mxx += w;

    	b[i] = {u, {v, w}};
    }

    if(n < mnx || n > mxx){
    	cout << -1 << "\n";
    	return;
    }

    sort(a.begin(), a.begin() + n);
    sort(b.begin(), b.begin() + m);

    for(int i = 0; i < m; ++i){

    	pre[i][0] = abs(b[i].ff - a[0]);

    	for(int j = 1; j < n; ++j){
    		pre[i][j] = pre[i][j - 1] + abs(b[i].ff - a[j]);
    	}
    }

    ll ans = slv(0, 0);
    cout << ans << "\n";
    
}

int main(){
    
    fast();

    solve();

    return 0;
}