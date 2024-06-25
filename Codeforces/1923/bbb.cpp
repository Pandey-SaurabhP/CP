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
    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> x(n);
    read(x, i, n);

    ll l = -1;
    ll r = 0;

    for(ll i = 0; i < n; ++i){
    	if(x[i] < 0){
    		l = i;
    		r = i + 1;
    	}
    }

    ll cleared = 0;
    ll fired;

    bool ok = 1;

    while(l >= 0 && r < n){

    	if(abs(x[l]) <= x[r]){

    		fired = abs(x[l]) * k;

    		if(fired - cleared - a[l] < 0){
    			ok = 0;
    			break;
    		}
    		else{
    			cleared += a[l];
    			--l;
    		}
    	}
    	else{
    		fired = abs(x[r]) * k;

    		if(fired - cleared - a[r] < 0){
    			ok = 0;
    			break;
    		}
    		else{
    			cleared += a[r];
    			++r;
    		}
    	}
    }

    while(l >= 0){
    	fired = abs(x[l]) * k;

    	if(fired - cleared - a[l] < 0){
			ok = 0;
			break;
		}
		else{
			cleared += a[l];
			--l;
		}
    }

    while(r < n){
    	fired = abs(x[r]) * k;

		if(fired - cleared - a[r] < 0){
			ok = 0;
			break;
		}
		else{
			cleared += a[r];
			++r;
		}
    }

    if(ok){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
    }
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