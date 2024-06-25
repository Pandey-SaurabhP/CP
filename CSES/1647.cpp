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

int segTree[mxn];
vector <int> a(mxn);

void build(int tl, int tr, int v){

	if(tl == tr){
		segTree[v] = a[tl];
		return;
	}

	if(tl > tr){
		return;
	}

	int mid = (tl + tr) / 2;

	build(tl, mid, 2 * v + 1);
	build(mid + 1, tr, 2 * v + 2);

	segTree[v] = min(segTree[2 * v + 1], segTree[2 * v + 2]);
}

int query(int tl , int tr, int l, int r, int v){
	
	if(tl > r || tr < l || tl > tr){ // Unoverlapping
		return INT_MAX;
	}
	if(tl >= l && r >= tr){ // Total Overlapping
		return segTree[v];
	}

	int mid = (tl + tr) / 2; // Partial overlapping

	int a1 = query(tl, mid, l, r, 2 * v + 1);
	int a2 = query(mid + 1, tr, l, r, 2 * v + 2);

	return min(a1, a2);
}

void solve() {
    memset(segTree, -1, sizeof(segTree));

    int n, q;
    cin >> n >> q;

    read(a, i, n);
    build(0, n - 1, 0);

    while(q--){
    	int l, r;
    	cin >> l >> r;

    	--l, --r;

    	cout << query(0, n - 1, l, r, 0) << "\n";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}