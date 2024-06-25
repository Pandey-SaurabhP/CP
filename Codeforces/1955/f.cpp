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

int dp[25][25][25][25];

int slv(int a, int b, int c, int d){
	if(a < 0 || b < 0 || c < 0 || d < 0) return 0;
	if(a == 0 && b == 0 && c == 0 && d == 0){
		return 0;
	}

	if(dp[a][b][c][d] != -1){
		return dp[a][b][c][d];
	}

	int ans = 0;

	if((a & 1) && (b & 1) && (c & 1) && !(d & 1)){
		++ans;
	}

	if(!(a & 1) && !(b & 1) && !(c & 1) && !(d & 1)){
		++ans;
	}

	ans += max(max(slv(a - 1, b, c, d), slv(a, b - 1, c, d)),
			       max(slv(a, b, c - 1, d), slv(a, b, c, d - 1)));

		return dp[a][b][c][d] = ans;
}


int a1(vector <int> a){


	vector <int> b = a;
	sort(b.rbegin(), b.rend());

    int ans = 0;

    if(b[0] & 1) --b[0];
    if(b[1] & 1) --b[1];
    if(b[2] & 1) --b[2];
    if(b[3] & 1) --b[3];

    ans += (b[0] + b[1] + b[2] + b[3]) / 2;

    return ans;
}

int a2(vector <int> a){


	int ans = 0;

	// Odd contribution. Fix a[3] till last
	if(a[0] == 0 || a[1] == 0 || a[2] == 0){
		return a[3] / 2;
	}

	ans += (a[2] + 1) / 2;
	ans += (a[1] - 1) / 2;
	ans += (a[0] - 1) / 2;
	ans += a[3] / 2;

	return ans;
}

void solve() {

	memset(dp, -1, sizeof(dp));

	vector <int> a(4);
	read(a, i, 4);

	cout << max(a1(a), a2(a)) << "\n"; 

// Odd contri

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