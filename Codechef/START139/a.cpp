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
const ll mxn = 100;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <bool> isPrime(mxn, 1);
vector <ll> smallest(mxn, INT_MAX);

void sieve(){

	for(ll i = 0; i < mxn; ++i){
		smallest[i] = i;
	}

	smallest[0] = smallest[1] = 0ll;
	isPrime[0] = isPrime[1] = 0ll;

	for(ll i = 2; i < mxn; ++i){

		if(isPrime[i]){

			smallest[i] = i;

			for(ll j = i * i; j < mxn; j += i){
				isPrime[j] = 0;

				smallest[j] = min(smallest[j], i);
			}
		}
	}
}

void solve() {
    ll k;
    cin >> k;

    ll n = smallest[k];
    cout << n << " -> ";
    ll mult = (n * (n + 1ll)) / 2ll;
    ll ans = k * (mult - 1ll);
    cout << ans << "\n";

}

int main(){
    
    fast();
	sieve();
	// print(smallest, i, 100);


    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}