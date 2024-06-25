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
    rep(i, 0, n){
    	read(a[i], j, m);
    }

    vector <vector <int>> b(n, vector <int> (m));
    rep(i, 0, n){
    	read(b[i], j, m);
    }

    vector <pii> row(n * m + 1, {-1, -1});
    vector <pii> col(n * m + 1, {-1, -1});

    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		row[a[i][j]].ff = i;
    		col[a[i][j]].ff = j;

    		row[b[i][j]].ss = i;
    		col[b[i][j]].ss = j;
    	}
    }

    int cntRow = 0, cntCol = 0;
    
    for(int i = 1; i <= n * m; ++i){
    	cntRow += (row[i].ff != row[i].ss);
    	cntCol += (col[i].ff != col[i].ss);

    	// cout << i << " -> " << row[i].ff << " " << row[i].ss << " :: " << col[i].ff << " " << col[i].ss << "\n";
    }

    cout << cntRow << " " << cntCol << "\n";

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