#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    vector <ll> a(n);
    read(a, i, n);

    sort(a.begin(), a.end());


	vector <ll> pre(n, 0);
	pre[0] = a[0];

	for(ll i = 1; i < n; ++i){
		pre[i] = pre[i - 1] + a[i];
	}	

	vector <ll> lastX(n, 0);
	lastX[0] = a[0];

	for(ll i = 1; i < n; ++i){
		lastX[i] = pre[i];

		if(i - x >= 0){
			lastX[i] -= pre[i - x];
		}
	}

    // print(a, i, n);
	// print(pre, i, n);
	// print(lastX, i, n);

	ll ans = (n - k <= 0? 0: -1000000000000000ll);

	for(ll i = max(n - k - 1, 0ll); i < n; ++i){
		ll cur = pre[i] - 2 * lastX[i];
		ans = max(ans, cur);
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