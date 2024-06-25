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

int dp[mxn][25];
int dp2[mxn][25];

bool cut(int u, int l, int r, int val, int lvl, int &req, vector <int> &a){

	if(l == r){
		if(a[l] - val == 0){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(lvl == req){

	}

	if(dp[u][val] != -1){
		return dp[u][val];
	}


	int mid = (l + r) / 2;

	return cut(2 * u + 1, l, mid, val + 1, a) & cut(2 * u + 2, mid + 1, r, val, a);
}

void solve() {
    int n;
    cin >> n;

	vector <int> a(n);
	read(a, i, n);

	dp.clear();

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