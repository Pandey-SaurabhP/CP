#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
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

vector <ll> segTree(mxn, 0);

void update(ll tl, ll tr, ll v, ll l, ll r, ll x){

	if(tl >= l && tr <= r){
		segTree[v] = x;
		return;
	}

	if(tr < l || tl > r) return;

	ll mid = (tl + tr) >> 1;

	update(tl, mid, 2 * v + 1, l, r, x);
	update(mid + 1, tr, 2 * v + 2, l, r, x);
}

ll query(ll tl, ll tr, ll v, ll x){


	if(tl > tr){
		return 0;
	}

	if(tl == tr){
		if(segTree[v] >= 1000000000){
			return 0;
		}
		return segTree[v];
	}

	ll mid = (tl + tr) >> 1;

	segTree[2 * v + 1] += segTree[v];
	segTree[2 * v + 2] += segTree[v];
	segTree[v] = 0;

	if(mid >= x){
		return query(tl, mid, 2 * v + 1, x);
	}
	else{
		return query(mid + 1, tr, 2 * v + 2, x);
	}

}

void solve() {
    string s;
    cin >> s;

    ll n = s.size();

    rep(i, 0, 4 * n){
    	segTree[i] = 0;
    }

    ll val = 0;
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
    	val += (s[i] == '(');
    	val -= (s[i] == ')');

    	ll q = query(0, n, 0, val);

    	if(val > 0) ans += q;

    	update(0, n, 0, val, val, q + 1);
    	// for(ll j = 0; j < n; ++j){
    	// 	cout << j << " : " << query(0, n, 0, j) << "\n";
    	// }
    	// cout << "\n";

    	// cout << "Val : 0 " << (val - 1) / 2 << "\n";
    	update(0, n, 0, 0, (val - 1) / 2, 1000000000);

    	// for(ll j = 0; j < n; ++j){
    	// 	cout << j << " : " << query(0, n, 0, j) << "\n";
    	// }
    	// cout << "\n\n\n\n";
    }

    cout << ans << "\n";
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