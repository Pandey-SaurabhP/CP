#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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
    ll n;
    cin >> n;

    vector <pii> a(n);

    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ff >> a[i].ss;
    }

    sort(a.begin(), a.end());

    ll ans = 0;

    vector<int> temp;
    for (int i = n - 1; i >= 0; i--) {
        int c = lower_bound(temp.begin(), temp.end(), a[i].ss) - temp.begin();
        ans += c;
        temp.insert(temp.begin() + c, a[i].ss);
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