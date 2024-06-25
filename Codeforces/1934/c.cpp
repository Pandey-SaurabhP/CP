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

ll binSearch(ll val){

	ll lo = 0;
	ll hi = 1000000000;

	while(lo <= hi){
		ll mid = (lo + hi) / 2;

		if(2 * mid == val){
			return mid;
		}
		else if(2 * mid > val){
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		}
	}

	return -1;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll r1, r2, r3, r4;

    cout << "? 1 1" << "\n";
    cin >> r1;

    cout << "? 1 " << m << "\n";
    cin >> r2;

    cout << "? " << n << " 1" << "\n";
    cin >> r3;

    cout << "? " << n << " " << m << "\n"; 
    cin >> r4;

    ll res = binSearch(r1 - r2 + m - 1);

    // cout << res << " " << r1 - r2 + m - 1 << "\n";

    if(r1 == 0){
    	cout << "! " << 1 << " " << 1 << endl << "\n";
    	return;
    }
    if(r2 == 0){
    	cout << "! " << 1 << " " << m << endl << "\n";
    	return;
    }
    if(r3 == 0){
    	cout << "! " << n << " " << 1 << endl << "\n";
    	return;
    }
    if(r4 == 0){
    	cout << "! " << n << " " << m << endl << "\n";
    	return;
    }


    if(res != -1){

    	ll x = r2 - m + 1 + res;
    	ll y = res;

    	if(x >= 0 && x < n && y >= 0 && y < m){
    		cout << "! " << x + 1 << " " << y + 1 << "\n";
    		return;
    	}
    }

	res = binSearch(r1 + r3 + 1 - n);

	// cout << res << " " << r1 + r3 + 1 - n << "\n";

	ll x = n - r3 - 1 + res;
	ll y = res;

	cout << "! " << x + 1 << " " << y + 1 << "\n";
    

}

int main(){
    
    // fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}