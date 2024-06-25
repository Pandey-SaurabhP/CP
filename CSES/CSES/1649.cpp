#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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

ll segTree[mxn];
vector <ll> a(mxn);

void build(ll tl, ll tr, ll v){
	if(tl > tr) return;

	if(tl == tr){
		segTree[v] = a[tl];
		return;
	}

	ll mid = (tl + tr) / 2;

	build(tl, mid, 2 * v + 1);
	build(mid + 1, tr, 2 * v + 2);

	segTree[v] = min(segTree[2 * v + 1], segTree[2 * v + 2]);
}

ll query(ll tl, ll tr, ll l, ll r, ll v){
	if(tl > r || tr < l){
		return INT_MAX;
	}

	if(tl >= l && tr <= r){
		return segTree[v];
	}

	ll mid = (tl + tr) / 2;

	ll q1 = query(tl, mid, l, r, 2 * v + 1);
	ll q2 = query(mid + 1, tr, l, r, 2 * v + 2);

	return min(q1, q2);
}

void update(ll tl, ll tr, ll v, ll id, ll val){
	if(tl > tr) return;

	if(tl == tr){
		segTree[v] = val;
		return;
	}

	ll mid = (tl + tr) / 2;

	if(id <= mid){
		update(tl, mid, 2 * v + 1, id, val);
	}
	else{
		update(mid + 1, tr, 2 * v + 2, id, val);
	}

	segTree[v] = min(segTree[2 * v + 1], segTree[2 * v + 2]);
}

void solve() {
	ll n, q;
	cin >> n >> q;
	
	read(a, i, n);

	build(0, n - 1, 0);

	// print(segTree, i, 2 * n);

	while(q--){
		ll t;
		cin >> t;

		if(t == 1){
			ll k, u;
			cin >> k >> u;
			--k;

			update(0, n - 1, 0, k, u);
		}
		else{
			ll l, r;
			cin >> l >> r;
			--l, --r;

			cout << query(0, n - 1, l, r, 0) << "\n";
		}
	}    
}

int main(){
    
    // fast();

    solve();

    return 0;
}