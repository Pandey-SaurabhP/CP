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

int m[10][10];

int gans = 0;

// int getSet(int n){

// 	vector <pii> xyz;

// 	for(int i = 0; i < n; ++i){
// 		for(int j = 0; j < n; ++j){
// 			if(m[i][j] == 1){
// 				xyz.pb({i, j});
// 			}
// 		}
// 	}

// 	set <int> st;
// 	for(int i = 0; i < xyz.size(); ++i){
// 		for(int j = 0; j < xyz.size(); ++j){
// 			st.insert(abs(xyz[i].ff - xyz[j].ff) + abs(xyz[i].ss - xyz[j].ss));
// 		}
// 	}

// 	return st.size();
// }

// bool slv(int i, int j, int k, int n){
// 	if(k == 0){
// 		gans = max(gans, getSet(n));

// 		if(gans == 2 * n - 1){
// 			for(int x = 0; x < n; ++x){
// 				for(int y = 0; y < n; ++y){
// 					cout << m[x][y] << " ";
// 				}
// 				cout << "\n";
// 			}
// 			cout << "\n";
// 			return 1;
// 		}

// 		return 0;
// 	}

// 	if(i == n || j == n){
// 		return 0;
// 	}


// 	if(j + 1 == n){
// 		m[i][j] = 1;
// 		if(slv(i + 1, j, k - 1, n)) return 1;
// 		m[i][j] = 0;
// 		if(slv(i + 1, j, k, n)) return 1;
// 	}
// 	else{
// 		m[i][j] = 1;
// 		if(slv(i, j + 1, k - 1, n)) return 1;
// 		m[i][j] = 0;
// 		if(slv(i, j + 1, k, n)) return 1;
// 	}


// }

void solve() {
	memset(m, 0, sizeof(m));

    int n;
    cin >> n;

    if(n == 2){
    	cout << 1 << " " << 1 << "\n";
    	cout << 1 << " " << 2 << "\n";
    }
    else{
	    for(int i = 0; i < n - 2; ++i){
	    	cout << 1 << " " << i + 1 << "\n";
	    }

	    cout << 2 << " " << n << "\n";
	    cout << n << " " << n << "\n"; 
	}

	cout << "\n";

    // gans = 0;
    // slv(0, 0, n, n);

    // cout << gans << "\n";

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