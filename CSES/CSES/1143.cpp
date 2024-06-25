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

	segTree[v] = max(segTree[2 * v + 1], segTree[2 * v + 2]);
}

pii query(ll tl, ll tr, ll l, ll r, ll v, ll x){
	if(tl > r || tr < l){
		return {INT_MIN, -1};
	}

	if(tl >= l && tr <= r){
		if(tl == tr){
			if(segTree[v] >= x){
				return {segTree[v], tl};
			}
			return {INT_MIN, -1};
		}

		if(segTree[v] >= x){
			int mid = (tl + tr) / 2;

			pii a1 = query(tl, mid, l, r, 2 * v + 1, x);
			if(a1.ff >= x){
				return a1;
			}

			pii a2 = query(mid + 1, tr, l, r, 2 * v + 2, x);
			return a2;
		}
		
		return {INT_MIN, -1};
		
	}

	ll mid = (tl + tr) / 2;

	pii q1 = query(tl, mid, l, r, 2 * v + 1, x);
	if(q1.ff >= x){
		return q1;
	}

	pii q2 = query(mid + 1, tr, l, r, 2 * v + 2, x);
	return q2;
}

void update(ll tl, ll tr, ll v, ll id, ll val){
	if(tl > tr) return;

	if(tl == tr){
		segTree[v] -= val;
		return;
	}

	ll mid = (tl + tr) / 2;

	if(id <= mid){
		update(tl, mid, 2 * v + 1, id, val);
	}
	else{
		update(mid + 1, tr, 2 * v + 2, id, val);
	}

	segTree[v] = max(segTree[2 * v + 1], segTree[2 * v + 2]);
}

void solve() {
    int n, m;
    cin >> n >> m;

    read(a, i, n);

    build(0, n - 1, 0);

    // print(segTree, i, 2 * n);

    vector <int> b(m);
    read(b, i, m);

    for(int i = 0; i < m; ++i){
    	pii q = query(0, n - 1, 0, n - 1, 0, b[i]);

    	if(q.ss != -1){
    		update(0, n - 1, 0, q.ss, b[i]);
    	}

    	cout << q.ss + 1 << " ";


    }
}

int main(){
    
    fast();

    solve();
    return 0;
}