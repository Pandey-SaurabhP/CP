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

ll getLeft(ll i, vector <ll> &a, vector <ll> &pre, vector <ll> &ldl, ll n){

	if(i - 1 >= 0 && a[i - 1] > a[i]){
		return 1;
	}
	if(i - 1 < 0){
		return INT_MAX;
	}

	ll lo = 0;
	ll hi = ldl[i - 1];

	ll ans = INT_MAX;

	// cout << a[i] << " : ";
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		// cout << lo << "\n";

		if(pre[i - 1] - (mid - 1 >= 0? pre[mid - 1]: 0) > a[i]){
			lo = mid + 1;
			ans = (i - mid);
		}
		else{
			hi = mid - 1;
		}
	}

	// cout << "\n";

	return ans;
}

ll getRight(ll i, vector <ll> &a, vector <ll> &post, vector <ll> &ldr, ll n){

	if(i + 1 < n && a[i + 1] > a[i]){
		return 1;
	}
	if(i + 1 >= n){
		return INT_MAX;
	}

	ll lo = ldr[i + 1];
	ll hi = n - 1;

	ll ans = INT_MAX;

	// cout << a[i] << " : ";

	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		// cout << lo << "\n";

		if(post[i + 1] - (mid + 1 < n? post[mid + 1]: 0) > a[i]){
			hi = mid - 1;
			ans = (mid - i);
		}
		else{
			lo = mid + 1;
		}
	}

	// cout << "\n";

	return ans;
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> pre(n, a[0]);
    vector <ll> post(n, a[n - 1]);

    for(ll i = 1; i < n; ++i){
    	pre[i] = pre[i - 1] + a[i];
    }

    for(ll i = n - 2; i >= 0; --i){
    	post[i] = post[i + 1] + a[i];
    }

    vector <ll> ldl(n, -1);
    for(ll i = 1; i < n; ++i){
    	if(a[i] == a[i - 1]){
    		ldl[i] = ldl[i - 1];
    	}
    	else{
    		ldl[i] = i - 1;
    	}
    }

    vector <ll> ldr(n, n);

    for(ll i = n - 2; i >= 0; --i){
    	if(a[i] == a[i + 1]){
    		ldr[i] = ldr[i + 1];
    	}
    	else{
    		ldr[i] = i + 1;
    	}
    }

    // print(ldl, i, n);
    // print(ldr, i, n);



    vector <ll> ans(n, -1);

    for(ll i = 0; i < n; ++i){

    	ans[i] = getLeft(i, a, pre, ldl, n);
    	ans[i] = min(ans[i], getRight(i, a, post, ldr, n));

    	if(ans[i] == INT_MAX){
    		ans[i] = -1;
    	}
    }

    print(ans, i, n);
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