#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
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

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    vector <int> pre(n + 1, 0);

    for(int i = 0; i < n; ++i){
    	pre[i + 1] = pre[i] ^ a[i];
    }

    int ans = 0;

    for(int l = 1; l <= n; ++l){
    	for(int r = l; r <= n; ++r){
    		// From l to r
    		for(int x = l; x <= r; ++x){
    			// Calculate from l to x, x to r, and l to r
    			int v1 = pre[x] ^ pre[l - 1];
    			int v2 = pre[r] ^ pre[x - 1];
    			int v3 = pre[r] ^ pre[l - 1];

    			if((v1 ^ v2) > v3){
    				cout << l << " " << x << " " << r << "\n";
    				++ans;
    			}
    		}
    	}
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