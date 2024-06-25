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

    ll i = 0;
    ll j = n - 1;

    bool turn = 0;

    while(i < j){

    	if(a[i] <= a[j]){

    		ll mn = a[i];
    		a[i] -= mn;
    		a[j] -= (mn - 1);

    		k -= (2 * mn) - 1;

    		if(k < 0){
    			a[i] += mn;
    			a[j] += mn - 1;
    			break;
    		}

    		if(k >= 1){
    			--a[j];
    			--k;
    		}
    		else{
    			break;
    		}

    		++i;
    	}
    	else{
    		ll mn = a[j];
    		a[i] -= mn;
    		a[j] -= mn;

    		k -= 2 * mn;

    		if(k < 0){
    			a[i] += mn;
    			a[j] += mn;
    			break;
    		}

    		--j;
    	}
    }

    if(i == j){
    	if(a[i] <= k){
    		a[i] = 0;
    		k -= a[i];
    	}
    }

    ll cnt = 0;

    for(ll i = 0; i < n; ++i){
    	cnt += (a[i] == 0);
    }

    cout << cnt << "\n";
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