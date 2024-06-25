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
const ll mxn = 1e6 + 1;
const ll mod = 1e9 + 7;
const ll lgn = 1e3 + 1;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int a[mxn];
int bit[lgn];
int sqn;

int query(int l, int r, int n){

	int bl = l / sqn;
	int br = r / sqn;

	int ans = 0;

	for(int i = bl + 1; i < br; ++i){
		ans += bit[i];
	}

	for(int i = l; i < min((bl + 1) * sqn, n); ++i){
		ans += a[i];
	}

	for(int i = r; i >= max(br * sqn, 0); --i){
		ans += a[i];
	}

	return ans;
}


void solve() {
    	
    int n, q;
    cin >> n >> q;

    read(a, i, n);

    int lo = 1;
    int hi = n;

    while(lo <= hi){
    	int mid = (lo + hi) / 2;

    	if(mid * mid <= n){
    		sqn = mid;
    		lo = mid + 1;
    	}
    	else{
    		hi = mid - 1;
    	}
    } 


    while(q--){
    	int l, r;
    	cin >> l >> r;

    	--l, --r;

    	cout << query(l, r, n) << "\n";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}