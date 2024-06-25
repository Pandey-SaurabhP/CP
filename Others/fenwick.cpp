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

int fenwick[mxn];
int n;

void update(int p, int x){

	for(int i = p; i < n; i = (i | (i + 1))){
		fenwick[i] += x;
	}
}

int queryHelp(int p){
	int ans = 0;

	for(int r = p; r >= 0; r = (r & (r + 1)) - 1){
		ans += fenwick[r];
	}

	return ans;
}

int query(int l, int r){
	return queryHelp(r) - (l - 1 >= 0? queryHelp(l - 1): 0);
}

void solve() {
	memset(fenwick, 0, sizeof(fenwick));

	cin >> n;

	vector <int> a(n);
	read(a, i, n);

	for(int i = 0; i < n; ++i){
		update(i, a[i]);
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