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
const ll inf = LONG_LONG_MAX;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll dist(pii a, pii b){
	ll ans = (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
	return ans;
}

void solve() {
    
    ll n;
    cin >> n;

    vector <pii> a(n);
    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ff >> a[i].ss;
    }

    sort(a.begin(), a.end());

    set <pii> b;
    b.insert({a[0].ss, a[0].ff});

    ll d = inf;

    int j = 0;

    for(ll i = 1; i < n; ++i){
    	// Search in the range ai - d

    	// ll search = (a[i].ss - d);

    	ll xyz = ceil(sqrt(d));

    	while((j < i) && (a[j].ff < (a[i].ff - xyz))){
    		b.erase({a[j].ss, a[j].ff});
    		++j;
    	}

    	auto lb = b.lower_bound({(a[i].ss - xyz), 0ll});
    	auto ub = b.upper_bound({(a[i].ss + xyz), 0ll});

    	for(auto j = lb; j != ub; ++j){
    		ll x = j -> ss;
    		ll y = j -> ff;

    		d = min(d, dist(a[i], {x, y}));
    	}

    	b.insert({a[i].ss, a[i].ff});
    }

    cout << d << "\n";
}

int main(){
    
    fast();

    solve();	

    return 0;
}