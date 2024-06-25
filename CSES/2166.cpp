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
ll pre[mxn];

vector <ll> a(mxn);

void update(ll tl, ll tr, ll v, ll k, ll u){

    if(tl == tr){
        segTree[v] = u;
        pre[v] = u;
        return;
    }

    ll mid = (tl + tr) / 2;

    if(k <= mid){
        update(tl, mid, 2 * v + 1, k, u);
    }
    else{
        update(mid + 1, tr, 2 * v + 2, k, u);
    }

    segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
    pre[v] = max(pre[2 * v + 1], segTree[2 * v + 1] + pre[2 * v + 2]);
}

pii query(ll tl, ll tr, ll l, ll r, ll v){

    if(tl >= l && tr <= r){
        return {segTree[v], pre[v]};
    }

    if(tl > r || tr < l){
        return {0, 0};
    }

    // cout << tl << " " << tr << "\n";

    ll mid = (tl + tr) / 2;

    pii q1 = query(tl, mid, l, r, 2 * v + 1);
    pii q2 = query(mid + 1, tr, l, r, 2 * v + 2);

    return {q1.ff + q2.ff, max(q1.ff + q2.ss, q1.ss)};
}

void solve() {

    memset(segTree, 0, sizeof(segTree));
    memset(pre, 0, sizeof(pre));

    ll n, q;
    cin >> n >> q;

    read(a, i, n);


    for(ll i = 0; i < n; ++i){
        update(0, n - 1, 0, i, a[i]);
    }

    // print(segTree, i, 4 * n);
    // print(pre, i, 4 * n);

    while(q--){
    	ll t;
    	cin >> t;

    	if(t == 1){
    		ll k, x;
    		cin >> k >> x;

    		--k;
            
            update(0, n - 1, 0, k, x);
    	}
    	else{
    		ll a, b;
            cin >> a >> b;

            --a, --b;

            pii q1 = query(0, n - 1, a, b, 0);

            cout << max(q1.ss, 0ll) << "\n";
    	}
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}