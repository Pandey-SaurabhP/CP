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
    int n;
    cin >> n;

	string s;
	cin >> s;

	int q;
	cin >> q;

	while(q--){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		int m1 = min(l1, l2);
		int m2 = max(r1, r2);

		int ans = 0;

		for(int i = m1; i < l1; ++i){
			ans += 2;
		}

		for(int i = m2; i > r1; --i){
			ans += 1;
		}

		for(int i = m1; i < l2; ++i){
			ans += 2;
		}

		for(int i = m2; i > r2; --i){
			ans += 1;
		}

		cout << ans << "\n";
	}	    
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