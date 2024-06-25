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

// Solve

void solve() {
    ll n, q;
    cin >> n >> q;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> pre(n + 1, 0);

    for(ll i = 1; i <= n; ++i){
    	pre[i] = pre[i - 1] + a[i - 1];
    }

    while(q--){
    	ll l, r;
    	cin >> l >> r;

    	cout << pre[r] - pre[l - 1] << "\n";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}