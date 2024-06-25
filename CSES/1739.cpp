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
const ll mxn = 1e3 + 1;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

string a[mxn];
ll dp[mxn][mxn];
ll sum[mxn][4 * mxn];
ll lazy[mxn][4 * mxn];


void build(ll tl, ll tr, ll i, ll v){
	if(tl == tr){
		sum[i][v] = dp[i][tl];
		return;
	}

	ll mid = (tl + tr) / 2;

	build(tl, mid, i, 2 * v + 1);
	build(mid + 1, tr, i, 2 * v + 2);

	sum[i][v] = sum[i][2 * v + 1] + sum[i][2 * v + 2];
}

void process(ll tl, ll tr, ll v, ll i){
	sum[i][v] += lazy[i][v] * (tr - tl + 1);
	lazy[i][2 * v + 1] += lazy[i][v];
	lazy[i][2 * v + 2] += lazy[i][v];
	lazy[i][v] = 0;
}

void update(ll tl, ll tr, ll v, ll l, ll r, ll x, ll i){

	if(tl <= tr){
		process(tl, tr, v, i);
	}

	if(tl >= l && tr <= r){
		sum[i][v] += x * (tr - tl + 1);
		lazy[i][2 * v + 1] += x;
		lazy[i][2 * v + 2] += x;
		return;
	}

	if(tl > r || tr < l){
		return;
	}

	ll mid = (tl + tr) / 2;

	update(tl, mid, 2 * v + 1, l, r, x, i);
	update(mid + 1, tr, 2 * v + 2, l, r, x, i);

	sum[i][v] = sum[i][2 * v + 1] + sum[i][2 * v + 2];
}

ll query(ll tl, ll tr, ll v, ll l, ll r, ll i){
 
	if(tl <= tr){
		process(tl, tr, v, i);
	}
 
	if(tl >= l && tr <= r){
		return sum[i][v];
	}
 
	if(l > tr || r < tl){
		return 0;
	}
 
	ll mid = (tl + tr) / 2;
 
	ll q1 = query(tl, mid, 2 * v + 1, l, r, i);
	ll q2 = query(mid + 1, tr, 2 * v + 2, l, r, i);
 
	return q1 + q2;
}


void solve() {
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));

    ll n, q;
    cin >> n >> q;

    read(a, i, n);

    for(ll i = 1; i <= n; ++i){
    	for(ll j = 1; j <= n; ++j){
    		dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i - 1][j - 1] == '*'? 1: 0);
    	}
    }



    for(int i = 0; i <= n; ++i){
    	build(0, n, i, 0);
    }

    // for(int i = 0; i <= n; ++i){
	// 	for(int j = 0; j <= n; ++j){
	// 		cout << query(0, n, 0, j, j, i) << " ";
	// 	}
	// 	cout << "\n";
	// }

    while(q--){
    	ll t;
    	cin >> t;

    	if(t == 2){
    		ll x1, y1, x2, y2;
    		cin >> x1 >> y1 >> x2 >> y2;

    		ll ans = 0;

    		int x2y2 = query(0, n, 0, y2, y2, x2);
    		int x1y2 = query(0, n, 0, y2, y2, x1 - 1);
    		int x2y1 = query(0, n, 0, y1 - 1, y1 - 1, x2);
    		int x1y1 = query(0, n, 0, y1 - 1, y1 - 1, x1 - 1);

    		ans = x2y2 - x1y2 - x2y1 + x1y1;

    		cout << ans << "\n";
    	}
    	else{
    		ll x, y;
    		cin >> x >> y;

    		for(ll i = x; i <= n; ++i){
    			update(0, n, 0, y, n, (a[x - 1][y - 1] == '*'? -1: 1), i);
    			a[x - 1][y - 1] = (a[x - 1][y - 1] == '*'? '.': '*');
    		}

    		// for(int i = 0; i <= n; ++i){
    		// 	for(int j = 0; j <= n; ++j){
    		// 		cout << query(0, n, 0, j, j, i) << " ";
    		// 	}
    		// 	cout << "\n";
    		// }
    	}
    }

}

int main(){
    
    fast();

    solve();

    return 0;
}