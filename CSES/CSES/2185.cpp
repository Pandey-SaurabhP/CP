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
    ll n, k;
    cin >> n >> k;

    vector <ll> a(k);
    read(a, i, k);

    ll ans = 0;

    for(ll i = 1; i < (1 << k); ++i){
    		
    	ll num = 1, cnt = 0, tmp = n;

    	for(ll j = 0; (1 << j) <= i; ++j){
    		if(i & (1 << j)){
    			tmp /= a[j];
    			++cnt;
    		}
    	}

    	if(cnt){
    		ans += (cnt % 2 == 0? -tmp: tmp);
    	}
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}