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

void solve() {
    int n, q;
    cin >> n >> q;

	vector <string> a(n);

	read(a, i, n);

	int pr[n + 1][n + 1];
	memset(pr, 0, sizeof(pr));

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1];
			pr[i][j] += (a[i - 1][j - 1] == '*');
		}
	}   

	while(q--){
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;

		int ans = pr[l2][r2] - pr[l2][r1 - 1] - pr[l1 - 1][r2] + pr[l1 - 1][r1 - 1];

		cout << ans << "\n";
	}
}

int main(){
    
    fast();

    solve();

    return 0;
}