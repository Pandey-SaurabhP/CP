#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
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

bool check(string s, int k, int n){

	vector <int> a(n, 0);
	bool toggle = 0;

	// 1011101010
	rep(i, 0, n - k){

		if(a[i] == 1){
			toggle ^= 1;
		}
		if(!((s[i] - '0') ^ toggle)){
			a[i] ^= 1;
			if(i + k < n) a[i + k] ^= 1;
			toggle ^= 1;
		}

	}

	// print(a, i, n);

	toggle = 0;

	rep(i, 0, n){
		if(a[i]) toggle ^= 1;
		if(!((s[i] - '0') ^ toggle)){
			return 0;
		}
	}

	return 1;

}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

	int lo = 1;
	int hi = n;

	int ans = 1;

	rrep(i, n, 1){
		if(check(s, i, n)){
			ans = i;
			break;
		}
	}   

	cout << ans << "\n";
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