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
const ll mxn = 1e3 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int bit[mxn];

void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

void solve() {
	memset(dp, 0, sizeof(dp));
	memset(segTree, 0, sizeof(segTree));

 	int q;
 	cin >> n >> q;

 	read(a, i, n);

 	for(int i = 1; i <= n; ++i){
 		for(int j = 1; j <= n; ++j){
 			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i - 1][j - 1] == '*');
 		}
 	}

 	while(q--){
 		int t;
 		cin >> t;

 		if(t == 2){
 			int x1, y1, x2, y2;
 			cin >> x1 >> y1 >> x2 >> y2;

 			int q1 = query(x1 - 1, y1 - 1) + dp[x1 - 1][y1 - 1];
 			int q2 = query(x1 - 1, y2) + dp[x1 - 1][y2];
 			int q3 = query(x2, y1 - 1) + dp[x2][y1 - 1];
 			int q4 = query(x2, y2) + dp[x2][y2];

 			cout << q4 - q3 - q2 + q1 << "\n";
 		}
 		else{
 			int x, y;
 			cin >> x >> y;

 			for(int i = x; i <= n; ++i){
 				update(y, n + 1, (a[x - 1][y - 1] == '*'? -1: 1), i);
 			}

 			a[x][y] = (a[x][y] == '*'? '.': '*');
 		}
 	}
}

int main(){
    
    fast();

    solve();

    return 0;
}