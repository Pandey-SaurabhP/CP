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

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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
    ll n, lim;
    cin >> n >> lim;

    vector <ll> a(n);
    read(a, i, n);

    ll cnt = 0;

    sort(a.begin(), a.end());

    for(ll i = 0; i < n; ++i){
    	// cout << a[i] << " : " << lim - a[i] + 1 << " " << (a[i] + 1) / 2 << "\n";
    	cnt += (lim - a[i] + 1);
    	cnt += (a[i] + 1) / 2;
    	if(a[i] == 0){
    		++cnt;
    	}

    	cnt -= i;

    	// Inclusion Exclusion
    }

    ll mxCnt = ((lim + 1) * (lim + 2)) / 2;

    cout << mxCnt - cnt << "\n";
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