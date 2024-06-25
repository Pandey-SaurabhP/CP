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

vector <ll> a(mxn);
ll segTree[mxn];
pii lazySet[mxn];
pii lazyAdd[mxn];

ll  tym = 0;

void build(ll tl, ll tr, ll v){

	if(tl == tr){
		segTree[v] = a[tl];
		return;
	}

	ll mid = (tl + tr) / 2;

	build(tl, mid, 2 * v + 1);
	build(mid + 1, tr, 2 * v + 2);

	segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}

void push(ll tl, ll tr, ll v){
	if(tl > tr) return;
	if(lazySet[v].ss == -1 && lazyAdd[v].ss == -1){
		return;
	}

	ll mid = (tl + tr) / 2;

	if(lazySet[v].ss > lazyAdd[v].ss){

		segTree[v] = (tr - tl + 1) * lazySet[v].ff;
		segTree[2 * v + 1] = (mid - tl + 1) * lazySet[v].ff;
		segTree[2 * v + 2] = (tr - mid) * lazySet[v].ff;

		lazySet[2 * v + 1] = lazySet[v];
		lazySet[2 * v + 2] = lazySet[v];

		lazyAdd[v] = {0, -1};
	}
	else{
		segTree[v] = (tr - tl + 1) * (lazySet[v].ff + lazyAdd[v].ff);
		segTree[2 * v + 1] = (mid - tl + 1) * (lazySet[v].ff + lazyAdd[v].ff);
		segTree[2 * v + 2] = (tr - mid) * (lazySet[v].ff + lazyAdd[v].ff);

		lazySet[2 * v + 1] = lazySet[v];
		lazySet[2 * v + 2] = lazySet[v];

		lazyAdd[2 * v + 1] = lazyAdd[v];
		lazyAdd[2 * v + 2] = lazyAdd[v];

		lazySet[v] = {0, -1};
		lazyAdd[v] = {0, -1};

	}
}

void updateAdd(ll tl, ll tr, ll v, ll l, ll r, ll x){

	push(tl, tr, v);

	// cout << tl << " " << tr << "\n";

	ll mid = (tl + tr) / 2;

	if(tl >= l && tr <= r){
		segTree[v] += (tr - tl + 1) * x;

		lazyAdd[2 * v + 1] = {x, tym};
		lazyAdd[2 * v + 2] = {x, tym};

		return;
	}

	if(tr < l || tl > r){
		return;
	}


	updateAdd(tl, mid, 2 * v + 1, l, r, x);
	updateAdd(mid + 1, tr, 2 * v + 2, l, r, x);

	segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}

void updateSet(ll tl, ll tr, ll v, ll l, ll r, ll x){
	// Set

	push(tl, tr, v);

	ll mid = (tl + tr) / 2;

	if(tl >= l && tr <= r){
		
		segTree[v] = (tr - tl + 1) * x;

		lazySet[2 * v + 1] = {x, tym};
		lazySet[2 * v + 2] = {x, tym};

		return;
	}

	if(tr < l || tl > r){
		return;
	}

	updateSet(tl, mid, 2 * v + 1, l, r, x);
	updateSet(mid + 1, tr, 2 * v + 2, l, r, x);

	segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}

ll query(ll tl, ll tr, ll v, ll l, ll r){
	push(tl, tr, v);


	if(tl >= l && tr <= r){
		return segTree[v];
	}

	if(tl > r || tr < l){
		return 0;
	}

	ll mid = (tl + tr) / 2;

	// cout << tl << " " << tr << " : " << v << "\n";

	ll q1 = query(tl, mid, 2 * v + 1, l, r);
	ll q2 = query(mid + 1, tr, 2 * v + 2, l, r);

	return q1 + q2;
}

void solve() {

	for(ll i = 0; i < mxn; ++i){
		lazyAdd[i] = lazySet[i] = {0, -1};
		segTree[i] = 0;
	}

    ll n, m;
    cin >> n >> m;

    read(a, i, n);

    build(0, n - 1, 0);

    while(m--){
    	ll t;
    	cin >> t;

    	if(t == 1){
    		ll l, r, x;
    		cin >> l >> r >> x;

    		--l, --r;

    		updateAdd(0, n - 1, 0, l, r, x);
    	}
    	else if(t == 2){
    		ll l, r, x;
    		cin >> l >> r >> x;

    		--l, --r;

    		updateSet(0, n - 1, 0, l, r, x);
    	}
    	else{
    		ll l, r;
    		cin >> l >> r;

    		--l, --r;

    		cout << query(0, n - 1, 0, l, r) << "\n";
    	}

    	++tym;
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}