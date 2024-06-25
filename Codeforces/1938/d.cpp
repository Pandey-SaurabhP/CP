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


bool check(vector <ll> &a, ll &n, ll x){

	vector <ll> pre(n + 1, 0);

	for(ll i = 1; i <= n; ++i){
		pre[i] = pre[i - 1] + a[i - 1];
	}

	ll lo = 0;

	ll bs = 0;

	// cout << "x : " << x << "\n";

	for(ll i = 1; i <= n; ++i){

		ll toSearch = pre[i] - x;
		ll lb = lower_bound(pre.begin() + lo, pre.end(), toSearch) - pre.begin();


		// cout << i << " : " << toSearch << " " << lb << "\n";

		if(lb != lo){

			if(lb != i - 1){
				if(a[lb - 1] >= a[i - 1]){
					bs += a[i - 1];
					lo = i;
				}
				else{
					bs += a[lb - 1];
					lo = lb;
				}
			}
			else{
				bs += a[i - 1];
				lo = i;
			}
			

			// cout << bs << "\n\n";
		}
	}

	// cout << "\n";

	if(bs <= x){
		// cout << "OK\n";
		return 1;
	}

	// cout << "\n\n";

	return 0;
}


void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    ll lo = 0;
    ll hi = 15;

    ll ans = 1000000000000000;

    while(lo <= hi){
    	ll mid = (lo + hi) / 2;

    	if(check(a, n, mid)){
    		ans = mid;
    		hi = mid - 1;
    	}
    	else{
    		lo = mid + 1;
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