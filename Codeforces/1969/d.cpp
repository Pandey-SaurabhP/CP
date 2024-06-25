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
typedef long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 3e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <pair <ll, pii>> profit(mxn);
vector <ll> a(mxn), b(mxn);

bool cmp(pair <ll, pii> x, pair <ll, pii> y){
	if(x.ff > y.ff) return 1;
	else if(x.ff < y.ff) return 0;
	return 1;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    read(a, i, n);
    read(b, i, n);

    vector <pii> vc;

    for(int i = 0; i < n; ++i){
    	if(b[i] - a[i] > 0){
    		vc.pb({a[i], b[i]});
    	}
    }

    n = vc.size();
    sort(vc.begin(), vc.end());

    

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