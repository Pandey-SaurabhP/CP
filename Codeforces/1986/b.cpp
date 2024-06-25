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

void solve() {
    int n, m;
    cin >> n >> m;

    vector <vector <int>> a(n, vector <int> (m));
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		cin >> a[i][j];
    	}
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		int mnVal = -1;

    		if(i - 1 >= 0){
    			mnVal = max(mnVal, a[i - 1][j]);
    		}
    		if(i + 1 < n){
    			mnVal = max(mnVal, a[i + 1][j]);
    		}
    		if(j - 1 >= 0){
    			mnVal = max(mnVal, a[i][j - 1]);
    		}
    		if(j + 1 < m){
    			mnVal = max(mnVal, a[i][j + 1]);
    		}

    		if(mnVal == -1) continue;
    		else{
    			a[i][j] = min(mnVal, a[i][j]);
    		}
    	}
    }

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		cout << a[i][j] << " ";
    	}
    	cout << "\n";
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