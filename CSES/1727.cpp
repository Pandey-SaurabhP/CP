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

ld lim = 1e3;


void solve() {
    int n, k;
    cin >> n >> k;

    ld xyz[n + 1][k + 1];
    int mult[n + 1][k + 1];

    ld den = 1.0 / k;

    memset(mult, 0, sizeof(mult));

    for(int i = 0; i < k + 1; ++i){
    	xyz[0][i] = 0;
    	xyz[1][i] = i;
    }

    for(int i = 2; i <= n; ++i){
    	for(int j = 0; j <= k; ++j){
    		xyz[i][j] = xyz[i - 1][j] * ld(j);
    		mult[i][j] = mult[i - 1][j];

    		if(mult[i][j] < n){
    			xyz[i][j] *= den;
    			++mult[i][j];
    		}
    	}
    }

    ld ans = 0ll;

	for(int j = 1; j <= k; ++j){
		ld cans = xyz[n][j] - xyz[n][j - 1];
		cans *= j;
		cans *= den;
		ans += cans;
	}

    cout << fixed << setprecision(6) << ans << "\n";
}

int main(){
    
    // fast();
    solve();

    return 0;
}