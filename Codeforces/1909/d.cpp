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

bool isPrime[mxn];
vector <ll> prime;

ll getGCD(ll a, ll b){
    return b == 0 ? a : getGCD(b, a % b);    
}
  

void solve() {

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, i, n);

    for(ll i = 0; i < n; ++i){
    	a[i] -= k;
    }

    ll gcd = a[0];
    for(auto it : a){
    	gcd = getGCD(gcd, it);
    }

    bool allZero = 1;
    bool allPos = 1;
    bool allNeg = 1;

    for(auto it : a){
    	if(it != 0){
    		allZero = 0;
    	}

    	if(it <= 0){
    		allPos = 0;
    	}

    	if(it >= 0){
    		allNeg = 0;
    	}
    }

    // cout << gcd << "\n";

    if(allZero){
    	cout << 0 << "\n";
    }
    else if(allPos){
    	ll ans = 0;

    	for(auto it : a){
    		ans += (it / gcd) - 1;
    	}

    	cout << ans << "\n";
    }
    else if(allNeg){

    	// print(a, i, n);
    	ll gcd = -a[0];

    	for(auto it : a){
    		gcd = getGCD(gcd, -it);
    	}

    	// cout << "GCD : " << -gcd << "\n";

    	ll ans = 0;

    	for(auto it : a){
    		ans += ((-it) / gcd) - 1;
    	}


    	cout << ans << "\n";
    }
    else{
    	cout << -1 << "\n";
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