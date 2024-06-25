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

vector <vector <ll>> matrixMultiply(vector <vector <ll>> a, vector <vector <ll>> b, ll n){
	vector <vector <ll>> ans(n, vector <ll> (n));

	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < n; ++j){

			ans[i][j] = 0;

			for(ll k = 0; k < n; ++k){
				ans[i][j] += (a[i][k] * b[k][j]) % mod;
				ans[i][j] %= mod;
			}
		}
	}

	return ans;
}

vector <vector <ll>> fastPower(vector <vector <ll>> b, ll e){

	vector <vector <ll>> ans = b;

	while(e){
		if(e & 1){
			ans = matrixMultiply(ans, b, 6);
			--e;
		}
		else{
			b = matrixMultiply(b, b, 6);
			e >>= 1;
		}
	}

	return ans;
}


void solve() {
    
    ll n;
    cin >> n;

    if(n <= 7){
    	switch(n){
    		case 1: cout << "1\n"; break;
    		case 2: cout << "2\n"; break;
    		case 3: cout << "4\n"; break;
    		case 4: cout << "8\n"; break;
    		case 5: cout << "16\n"; break;
    		case 6: cout << "32\n"; break;
    		case 7: cout << "63\n"; break;
    		default: cout << "0\n"; break;
    	}
    }
    else{

    	vector <ll> p = {32, 16, 8, 4, 2, 1};
    	vector <vector <ll>> a = { {1, 1, 1, 1, 1, 1}, 
    								{1, 0, 0, 0, 0, 0}, 
    								{0, 1, 0, 0, 0, 0}, 
    								{0, 0, 1, 0, 0, 0}, 
    								{0, 0, 0, 1, 0, 0}, 
    								{0, 0, 0, 0, 1, 0} };

    	a = fastPower(a, n - 7);

    	ll ans = 0;

    	// for(ll i = 0; i < 6; ++i){
    	// 	for(ll j = 0; j < 6; ++j){
    	// 		cout << a[i][j] << " ";
    	// 	}
    	// 	cout << "\n";
    	// }
    	// cout << "\n";

    	for(ll i = 0; i < 6; ++i){
    		ans += (p[i] * a[0][i]) % mod;
    		ans %= mod;
    	}

    	cout << ans << "\n";


    }
}

int main(){
    
    fast();
    solve();

    return 0;
}