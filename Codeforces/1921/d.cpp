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
    ll n, m;
    cin >> n >> m;

    vector <ll> a(n), b(m);

    read(a, i, n);
    read(b, i, m);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll l = 0;
    ll r = n - 1;

    ll ans = 0;

    ll l2, r2;
    l2 = 0;
    r2 = m - 1;

    while(l <= r){
    	ll res1 = abs(a[l] - b[r2]);
    	ll res2 = abs(a[r] - b[l2]);

    	if(res1 >= res2){
    		++l;
    		--r2;

    		ans += res1;
    	}
    	else{
    		--r;
    		++l2;

    		ans += res2;
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