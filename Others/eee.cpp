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

vector <ll> primeList;
vector <bool> isPrime(mxn, 1);

vector <ll> lst;

void sieve(){

	isPrime[0] = isPrime[1] = 0;

	for(ll i = 2; i < mxn; ++i){
		if(isPrime[i]){
			primeList.pb(i);
			for(ll j = i * i; j < mxn; j += i){
				isPrime[j] = 0;
			}
		}
	}
}

void solve() {
    ll n;
    cin >> n;

    bool ok = 0;

    for(ll i = 0; i < primeList.size(); ++i){

    	ll c = primeList[i] * primeList[i];

    	if(n - c >= 0 && binary_search(lst.begin(), lst.end(), n - c)){

    		if(c == n - c - 4) continue;
    		ok = 1;
    		break;
    	}
    }

    if(ok){
    	cout << "Yes\n";
    }
    else{
    	cout << "No\n";
    }
}

int main(){
    
    fast();

    sieve();

    ll sz = primeList.size();
    ll xyz = 0;


	for(ll j = 0; j < sz; ++j){

		ll a = 2ll;
		ll b = primeList[j];

		ll n = a * a + b * b;

		lst.pb(n);

		++xyz;
	}
    

    sort(lst.begin(), lst.end());


    // print(lst, i, 100);

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}