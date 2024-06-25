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
    ll n, k;
    cin >> n >> k;

    --k;

    vector <ll> a(n);
    read(a, i, n);

    ll dpf[n];
    for(int i = 0; i < n; ++i) dpf[i] = 0;

    for(ll i = k + 1; i < n; ++i){
    	dpf[i] = a[i] + dpf[i - 1];
    	
    	if(i - 2 >= 0){
    		dpf[i] = max(dpf[i], a[i] + dpf[i - 2]);
    	}
    }

    ll dpb[n];
    dpb[n - 1] = a[n - 1];

    for(ll i = n - 2; i >= 0; --i){
    	dpb[i] = a[i] + dpb[i + 1];

    	if(i + 2 < n){
    		dpb[i] = max(dpb[i], a[i] + dpb[i + 2]);
    	}
    }

    print(dpf, i, n);
    print(dpb, i, n);

    ll ans = 0;

    for(ll i = k; i < n; ++i){
    	ans = max(ans, dpf[i] + dpb[0] - dpb[i]);
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}