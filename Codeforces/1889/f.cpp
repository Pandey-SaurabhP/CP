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
	int n, q;
	cin >> n >> q;

	for(int i = 0; i < n - 1; ++i)   {
		cout << i + 1 << " " << i + 2 << "\n";
	}

	int curPar = n - 1;

	for(int i = 0; i < q; ++i){
		int d;
		cin >> d;

		// Pick the nth vertex put it on side of n - dth vertex

		if(n - d == curPar){
			cout << "-1 -1 -1\n";
		}
		else{
			cout << n << " " << curPar << " " << n - d << "\n";
			curPar = n - d;
		}
	}
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