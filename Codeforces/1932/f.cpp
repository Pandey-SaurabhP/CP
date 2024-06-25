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
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector <pii> a(m);

    rep(i, 0, m - 1){
    	cin >> a[i].ff >> a[i].ss;
    }

    vector <ll> cont(n + 2, 0), mx(n + 2, 0);

    ll mx2 = -1;
    ll mn2 = a[0].ff;
	
	rep(i, 0, m - 1){
		cont[a[i].ff]++;
		cont[a[i].ss + 1]--;

		mx[a[i].ff] = max(mx[a[i].ff], a[i].ss);

		mx2 = max(a[i].ss, mx2);
		mn2 = min(a[i].ff, mn2);
	} 

	mx[mx2 + 1] = n + 1;

	for(ll i = 1; i <= n; ++i){
		cont[i] = cont[i - 1] + cont[i];
		mx[i] = max(mx[i - 1], mx[i]);
	}

	vector <ll> dp(n + 3, 0);

	for(int i = n; i >= 0; --i){
		dp[i] = max(cont[i] + dp[mx[i] + 1], dp[i + 1]);
	}

	ll ans = 0;

	rep(i, 0, n + 1){
		ans = max(ans, dp[i]);
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