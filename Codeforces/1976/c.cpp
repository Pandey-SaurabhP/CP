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

void solve() {
    ll n, m;
    cin >> n >> m;

    vector <ll> a(n + m + 1), b(n + m + 1);
    read(a, i, n + m + 1);
    read(b, i, n + m + 1);

	vector <ll> pre1(n + m + 1, (a[0] > b[0]? a[0]: b[0]));
	vector <ll> t(n + m + 1, b[0] > a[0]), p(n + m + 1, a[0] > b[0]);

	for(ll i = 0; i < n + m; ++i){
		pre1[i + 1] = pre1[i] + (a[i + 1] > b[i + 1]? a[i + 1]: b[i + 1]);

		p[i + 1] = p[i] + (a[i + 1] > b[i + 1]);
		t[i + 1] = t[i] + (a[i + 1] < b[i + 1]);
	}    

	vector <ll> ps(n + m + 1, a[n + m]), ts(n + m + 1, b[n + m]);
	for(ll i = n + m - 1; i >= 0; --i){
		ps[i] = ps[i + 1] + a[i];
		ts[i] = ts[i + 1] + b[i];
	}

	if(n == 0 || m == 0){

		vector <ll> ans(n + m + 1, 0);

		if(n == 0){
			for(ll i = 0; i < n + m + 1; ++i){
				ans[i] = ts[0];
				ans[i] -= b[i];
			}
		}
		else{
			for(ll i = 0; i < n + m + 1; ++i){
				ans[i] = ps[0];
				ans[i] -= a[i];
			}
		}

		print(ans, i, n + m + 1);
		return;
	}

	// print(pre1, i, n + m + 1);
	// print(p, i, n + m + 1);
	// print(t, i, n + m + 1);
	// print(ps, i, n + m + 1);
	// print(ts, i, n + m + 1);

	vector <ll> ans(n + m + 1, 0);

	for(ll i = 0; i < n + m + 1; ++i){

		
		ll lo = 0;
		ll hi = n + m;

		// Find the min index with match of p or t

		ll sub = (a[i] > b[i]? 1: 2);
		ll aa = hi;

		while(lo <= hi){
			ll mid = (lo + hi) >> 1;

			ll prog = p[mid] - (mid >= i? sub == 1: 0);
			ll test = t[mid] - (mid >= i? sub == 2: 0);

			if(prog >= n || test >= m){
				// Trie lowering
				aa = mid;
				hi = mid - 1;
			}
			else{
				lo = mid + 1;
			}
		}

		// Found index at aa
		// cout << "Index : " << aa << " ";

		ans[i] += pre1[aa];

		// cout << ans[i] << " ";

		if(p[aa] >= n){
			ans[i] += (aa + 1 <= n + m? ts[aa + 1]: 0);

			// cout << "ts " << ans[i] << " ";
		}
		else if(t[aa] >= m){
			ans[i] += (aa + 1 <= n + m? ps[aa + 1]: 0);
			// cout << "ps " << ans[i] << " ";
		}

		if(aa > i){
			ans[i] -= (a[i] > b[i]? a[i]: b[i]);
			// cout << "rem1 " << ans[i] << " ";
		}
		else{
			if(p[aa] == n){
				// Must have picked programmer
				ans[i] -= b[i];

				// cout << "rem2 " << ans[i] << " ";
			}
			else{
				ans[i] -= a[i];
				// cout << "rem3 " << ans[i] << " ";
			}
		}

		// cout << "\n";
	}

	// cout << "Ans : ";
	print(ans, i, n + m + 1);
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