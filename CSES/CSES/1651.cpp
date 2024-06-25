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

void update(ll tl, ll tr, ll l, ll r, ll v, ll x){

	if(tl > tr){
		return;
	}

	if(tl > r || tr < l) return;

	if(tl >= l && tr <= r){
		segTree[v] += x;
		return;
	}

	ll mid = (tl + tr) / 2;

	update(tl, mid, l, r, 2 * v + 1, x);
	update(mid + 1, tr, l, r, 2 * v + 2, x);
} 

ll query(ll tl, ll tr, ll v, ll id){

	if(tl > tr){
		return 0;
	}

	if(tl == tr){
		return segTree[v] + a[tl];
	}

	ll mid = (tl + tr) / 2;
	segTree[2 * v + 1] += segTree[v];
	segTree[2 * v + 2] += segTree[v];
	segTree[v] = 0;

	if(id <= mid){
		return query(tl, mid, 2 * v + 1, id);
	}
	else{
		return query(mid + 1, tr, 2 * v + 2, id);
	}
}

void solve() {
	memset(segTree, 0, sizeof(segTree));

    ll n, q;
    cin >> n >> q;

    read(a, i, n);

    while(q--){
    	ll t;
    	cin >> t;

    	if(t == 1){
    		ll l, r, u;
    		cin >> l >> r >> u;

    		--l, --r;

    		update(0, n - 1, l, r, 0, u);
    	}
    	else{
    		ll i;
    		cin >> i;

    		--i;

    		cout << query(0, n - 1, 0, i) << "\n";
    	}
    }
}

int main(){
    
    // fast();

    solve();

    return 0;
}