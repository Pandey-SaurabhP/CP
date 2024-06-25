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

ll a[mxn];

ll sum[2 * mxn];
ll lazy[2 * mxn];
ll lop[2 * mxn];
ll lazy2[2 * mxn];

void process(ll tl, ll tr, ll v){
	if(tl <= tr){
		if(lop[v] == 1){ // Add
			sum[v] += lazy[v] * (tr - tl + 1);
			lazy[2 * v + 1] += lazy[v];
			lazy[2 * v + 2] += lazy[v];

			if(lop[2 * v + 1] >= 2){
				lop[2 * v + 1] = 3;
			}
			else{
				lop[2 * v + 1] = 1;
			}
			if(lop[2 * v + 2] >= 2){
				lop[2 * v + 2] = 3;
			}
			else{
				lop[2 * v + 1] = 1;
			}

			lazy[v] = 0;
		}
		else if(lop[v] == 2 && lazy2[v] != 0){ // Equal
			sum[v] = lazy2[v] * (tr - tl + 1);
			lazy2[2 * v + 1] = lazy2[v];
			lazy2[2 * v + 2] = lazy2[v];
			lop[2 * v + 1] = lop[2 * v + 2] = 2;
			lazy2[v] = 0;

			lazy[v] = lazy[2 * v + 1] = lazy[2 * v + 2] = 0;
		}
		else if(lop[v] == 3){ // Assign and Add
			sum[v] = (lazy[v] + lazy2[v]) * (tr - tl + 1);
			lazy2[2 * v + 1] = lazy2[v];
			lazy2[2 * v + 2] = lazy2[v];

			lazy[2 * v + 1] += lazy[v];
			lazy[2 * v + 2] += lazy[v];

			lop[2 * v + 1] = lop[2 * v + 2] = 3;
			
			lazy2[v] = 0;
		}

		lop[v] = 0;
	}
}

void updateSet(ll tl, ll tr, ll v, ll l, ll r, ll x){

	process(tl, tr, v);

	if(tl >= l && tr <= r){
		sum[v] = x * (tr - tl + 1);
		lazy2[2 * v + 1] = lazy2[2 * v + 2] = x;

		lazy[v] = lazy[2 * v + 1] = lazy[2 * v + 2] = 0;

		lop[v] = 0;
		lop[2 * v + 1] = lop[2 * v + 2] = 2;

		return;
	}

	if(l > tr || r < tl){
		return;
	}

	ll mid = (tl + tr) / 2;

	updateSet(tl, mid, 2 * v + 1, l, r, x);
	updateSet(mid + 1, tr, 2 * v + 2, l, r, x);

	sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
}

void updateAdd(ll tl, ll tr, ll v, ll l, ll r, ll x){

	process(tl, tr, v);

	if(tl >= l && tr <= r){
		sum[v] += x * (tr - tl + 1);

		lazy[2 * v + 1] += x; 
		lazy[2 * v + 2] += x;

		lop[v] = 0;
		if(lop[2 * v + 1] >= 2){
			lop[2 * v + 1] = 3;
		}
		else{
			lop[2 * v + 1] = 1;
		}
		if(lop[2 * v + 2] >= 2){
			lop[2 * v + 2] = 3;
		}
		else{
			lop[2 * v + 1] = 1;
		}

		return;
	}

	if(l > tr || r < tl){
		return;
	}

	ll mid = (tl + tr) / 2;

	updateAdd(tl, mid, 2 * v + 1, l, r, x);
	updateAdd(mid + 1, tr, 2 * v + 2, l, r, x);

	sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
}

ll query(ll tl, ll tr, ll v, ll l, ll r){

	process(tl, tr, v);

	if(tl >= l && tr <= r){
		return sum[v];
	}

	if(l > tr || r < tl){
		return 0;
	}

	ll mid = (tl + tr) / 2;

	ll q1 = query(tl, mid, 2 * v + 1, l, r);
	ll q2 = query(mid + 1, tr, 2 * v + 2, l, r);

	return q1 + q2;
}

void solve() {
	memset(sum, 0, sizeof(sum));
	memset(lazy, 0, sizeof(lazy));
	memset(lazy2, 0, sizeof(lazy2));
	memset(lop, 0, sizeof(lop));

    ll n, q;
    cin >> n >> q;

    read(a, i, n);

    for(ll i = 0; i < n; ++i){
    	updateAdd(0, n - 1, 0, i, i, a[i]);
    }

    while(q--){
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
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}