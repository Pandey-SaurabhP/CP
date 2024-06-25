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

int slv(int i, int j, vector <int> &a, vector <char> &op){
	if(i == j){
		return a[i];
	}
	else if(i == j - 1){
		return a[i] + (op[i] == '+'? 1: -1) * a[j];
	}

	int ans = INT_MIN;
	for(int k = i; k < j; ++k){
		ans = max(ans, slv(i, k, a, op) + (op[k] == '+'? 1: -1) * slv(k + 1, j, a, op));
	}

	return ans;
}

void solve() {

	vector <int> a = {1, 3, 2, 5, 1, 6, 7};
	vector <char> op = {'+', '-', '-', '+', '-', '+'};

	int n = a.size();

	cout << slv(0, n - 1, a, op);
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