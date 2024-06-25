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

// Solve
vector <ll> primes;
bool isPrime[50005];

void sieve(){

	memset(isPrime, 1, sizeof(isPrime));

	for(ll i = 2; i < 50005; ++i){
		if(!isPrime[i]) continue;
		isPrime[i] = 1;

		primes.pb(i);

		for(ll j = 2 * i; j < 50005; j += i){
			isPrime[j] = 0;
		}
	}
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    // Get prime numbers upto 50k
    sieve();

    int mx = 0;

    for(auto it : primes){
    	int cur = 0;

    	for(int i = 0; i < n; ++i){
    		if(a[i] % it == 0){
    			++cur;
    		}
    	}

    	mx = max(mx, cur);
    }

    cout << mx << "\n";
}

int main(){
    
    fast();
        solve();
    

    return 0;
}