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

ll fct[mxn];

ll perm(ll x){
	return fct[x] % mod;
}



void solve() {
    ll n;
    cin >> n;

    vector <int> a(n);

    for(ll i = 1; i <= n; ++i){
    	if(i == 1 || i == n){
    		cout << perm(n);
    	}
    	else{
    		cout << perm(2 * (i - 1)) % mod;
    	}
    	cout << " ";
    }
    cout << "\n";

    // print(a, i, n);
}

int main(){
    
    fast();

    fct[0] = 1;
    for(ll i = 1; i <= mxn; ++i){
    	fct[i] = (fct[i - 1] * i) % mod;
    }

    ll t;
    cin >> t;



    while(t--){
        solve();
    }

    return 0;
}