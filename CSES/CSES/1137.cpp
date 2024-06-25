#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 5e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <ll>> adj(mxn);

ll segTree[mxn];
ll lazy[mxn];

vector <ll> flattened(mxn);
vector <ll> cnt(mxn);

ll x = 0;
 
void build(ll l, ll r, ll i, vector <ll> &a, ll &n){
    if(l == r){
        segTree[i] = a[l];
        return;
    }
 
    ll mid = (l + r) / 2;
 
    build(l, mid, 2 * i + 1, a, n);
    build(mid + 1, r, 2 * i + 2, a, n);
 
    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2]; // Sum
}
 
void push(ll v) {
    segTree[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];

    segTree[v * 2 + 2] += lazy[v];
    lazy[v * 2 + 2] += lazy[v];

    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r){
        return;
    }
    if (l == tl && tr == r) {
        segTree[v] += (addend - segTree[v]);
        lazy[v] += (addend - segTree[v]);
    } 
    else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2+1, tl, tm, l, min(r, tm), addend);
        update(v*2+2, tm+1, tr, max(l, tm+1), r, addend);
        segTree[v] = segTree[v * 2 + 1] + segTree[v * 2 + 2];
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r){
        return 0;
    }
    if (l == tl && tr == r){
        return segTree[v];
    }

    push(v);
    ll tm = (tl + tr) / 2;
    return query(v*2 + 1, tl, tm, l, min(r, tm))+
               query(v*2+2, tm+1, tr, max(l, tm+1), r);
}

// ***

ll flatten(ll root, ll par){
	flattened[x++] = root; 
	ll childrens = 0;

	for(auto it : adj[root]){
		if(it != par){
			childrens += flatten(it, root);
		}
	}

	cnt[root] = childrens;
	return 1 + childrens;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector <ll> a(n);
    read(a, i, n);

    for(ll i = 0; i < n - 1; ++i){
    	ll u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    flatten(0, 0);

    // print(flattened, i, n);
    // print(cnt, i, n);

    // Replace each node by its value

    vector <ll> val(n);
    vector <ll> id(n);

    for(ll i = 0; i < n; ++i){
    	val[i] = a[flattened[i]];
    	id[flattened[i]] = i;
    }

    // print(val, i, n);
    // print(id, i, n);

    build(0, n - 1, 0, val, n);

    while(q--){
    	ll t;
    	cin >> t;

    	if(t == 1){
    		ll u, v;
    		cin >> u >> v;

    		// Update
    		--u;

    		ll startId = id[u];

    		// cout << startId << " " << endId << "\n";

    		update(0, 0, n - 1, startId, startId, v);
    	}
    	else{
    		ll u;
    		cin >> u;
    		--u;

    		ll startId = id[u];
    		ll endId = id[u] + cnt[u];

    		cout << query(0, 0, n - 1, startId, endId) << "\n";
    	}
    }

    
}

int main(){
    
    fast();

    solve();
    
    return 0;
}