#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int dp[mxn][30][2];

bool cut(int u, int l, int r, int val, int type, vector <int> &a){



	if(l == r){
		if(a[l] - val == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(dp[u][val][type] != -1){
		return dp[u][val][type];
	}


	int mid = (l + r) / 2;

	if(mid - l == r - mid - 1){
		// cout << "C1\n";
		return  dp[u][val][type] = (cut(2 * u + 1, l, mid, val + 1, 0, a) & cut(2 * u + 2, mid + 1, r, val, 0, a)) |
				(cut(2 * u + 1, l, mid, val, 0, a) & cut(2 * u + 2, mid + 1, r, val + 1, 0, a));
	}
	else{
		// cout << "C2\n";
		return  dp[u][val][type] = (cut(2 * u + 1, l, mid, val + 1, 1, a) & cut(2 * u + 2, mid + 1, r, val, 1, a)) |
				(cut(2 * u + 1, l, mid, val, 1, a) & cut(2 * u + 2, mid + 1, r, val + 1, 1, a)) |
				(cut(2 * u + 1, l, mid - 1, val + 1, 0, a) & cut(2 * u + 2, mid, r, val, 0, a)) |
				(cut(2 * u + 1, l, mid - 1, val, 0, a) & cut(2 * u + 2, mid, r, val + 1, 0, a));
	}

}

void solve() {
    int n;
    cin >> n;

	vector <int> a(n);
	read(a, i, n);

	for(int i = 0; i < 5 * n + 1; ++i){
		for(int j = 0; j < 30; ++j){
			dp[i][j][0] = dp[i][j][1] = -1;
		}
	}

	bool ans = cut(0, 0, n - 1, 0, 0, a);

	if(ans){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
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