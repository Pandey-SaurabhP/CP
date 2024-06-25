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
ll inf = 2e17 + 5;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

bool check(vector <ll> &a, ll x, ll lim){
	ll n = a.size();

	ll done = 0ll;

	for(ll i = 0ll; i < n; ++i){
		done += max(0ll, x - a[i]);
		if(done > lim){
			return 0;
		}
	}

	if(done > lim) return 0;
	return 1;
}

ll maxVal(vector <ll> &a, ll n, ll mid, ll k){

	for(ll i = 0; i < n; ++i){
		if(a[i] < mid){
			k -= (mid - a[i]);
			a[i] = mid;
		}
	}

	ll ans = (n * mid) - (n - 1);

	for(int i = 0; i < n; ++i){
		if(k > 0ll && a[i] <= mid){
			++a[i];
			--k;
		}

		if(a[i] > mid){
			++ans;
		}
	}

	return ans;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, i, n);

    ll lo = 0ll;
    ll hi = inf;
    ll ans = 0ll;

    while(lo <= hi){
    	ll mid = (lo + hi) >> 1ll;

    	if(check(a, mid, k)){
    		ans = mid;
    		lo = mid + 1ll;
    	}
    	else{
    		hi = mid - 1ll;
    	}
    }

    ans = max(ans, maxVal(a, n, ans, k));
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