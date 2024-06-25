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

// [(00) (01)] [(00) (01)] = [0000+0110 0001+0111]
// [(10) (11)] [(10) (11)] = []

// Solve
vector <vector <ll>> matMul(vector <vector <ll>> a, vector <vector <ll>> b){

	vector <vector <ll>> ans(2, vector <ll> (2));
	for(ll i = 0; i < 2; ++i){
		for(ll j = 0; j < 2; ++j){
			for(ll k = 0; k < 2; ++k){
				ans[i][j] += a[i][k] * b[k][j] % mod;
				ans[i][j] %= mod;
			}
		}
	}

	return ans;
}

vector <vector <ll>> fastPower(vector <vector <ll>> b, ll e){
	vector <vector <ll>> ans = b;

	while(e){
		if(e & 1ll){
			ans = matMul(ans, b);
			--e;
		}
		else{
			b = matMul(b, b);
			e >>= 1ll;
		}
	}

	return ans;
}

void solve() {
    ll n;
    cin >> n;

    vector <vector <ll>> b = {{0, 1}, {1, 1}};
    vector <vector <ll>> ans = fastPower(b, n);    
    cout << ans[0][0] << "\n";

}

int main(){
    
    fast();

    solve();
    return 0;
}