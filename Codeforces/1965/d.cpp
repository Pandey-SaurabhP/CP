#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

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


int getLastBit(int x){
	int i = -1;
	while(x){
		x >>= 1;
		++i;
	}

	return i;
}


void solve() {

    
    int n, k;
    cin >> n >> k;

    int mult = 1;
    vector <int> all;
    for(int i = 0; i <= 20; ++i){

    	if(i == getLastBit(k)){
    		mult <<= 1;
    		continue;
    	}

    	all.pb(mult);
    	mult <<= 1;
    }

    all.pb(k - (1 << getLastBit(k)));
    all.pb(k + 1);
    all.pb(k + (1 << getLastBit(k)) + 1);

    cout << all.size() << "\n";
    print(all, i, all.size());
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