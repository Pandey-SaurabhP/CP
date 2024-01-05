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

void solve() {
    ll n, m;
    cin >> n >> m;

    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;


    ll oneTile = 0;

    // No cover area
    if(m % 2 == 1){
    	oneTile += ((x1 - 1) + (n - x2));
	}


	// Cover Area

	// Left Side
	ll cntRows = x2 - x1 + 1;

	if(y1 % 2 == 0){
		oneTile += cntRows;
	}


	// Right Side
	if((m - y2) % 2 == 1){
		oneTile += cntRows;
	}


	cout << (oneTile + 1) / 2 << "\n";


}

int main(){
    
    fast();

    solve();

    return 0;
}