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
ll mx[mxn];
ll smx[mxn];
ll mxf[mxn];
ll smxf[mxn];

void merge(ll v){
    map <int, int> mp;

    mp[mx[2 * v + 1]] += mxf[2 * v + 1];
    mp[smx[2 * v + 1]] += smxf[2 * v + 1];
    mp[mx[2 * v + 2]] += mxf[2 * v + 2];
    mp[smx[2 * v + 2]] += smxf[2 * v + 2];

    vector <int> xyz;
    for(auto it : mp){
        xyz.pb(it.ff);
    }

    sort(xyz.rbegin(), xyz.rend());

    mx[v] = xyz[0];
    mxf[v] = mp[xyz[0]];

    smx[v] = xyz[1];
    smxf[v] = mp[xyz[1]];
}

void update(ll tl, ll tr, ll v, ll p, ll x){
    if(tl == tr){
        mx[v] = x;
        mxf[v] = 1;

        smx[v] = 0;
        smxf[v] = 0;
        return;
    }

    ll mid = (tl + tr) / 2;

    if(p <= mid){
        update(tl, mid, 2 * v + 1, p, x);
    }
    else{
        update(mid + 1, tr, 2 * v + 2, p, x);
    }

    merge(v);
}

pair <pii, pii> process(pair <pii, pii> p1, pair <pii, pii> p2){
    
    map <int, int> mp;

    mp[p1.ff.ff] += p1.ff.ss;
    mp[p1.ss.ff] += p1.ss.ss;
    mp[p2.ff.ff] += p2.ff.ss;
    mp[p2.ss.ff] += p2.ss.ss;

    vector <int> xyz;
    for(auto it : mp){
        xyz.pb(it.ff);
    }

    sort(xyz.rbegin(), xyz.rend());

    return {{xyz[0], mp[xyz[0]]}, {xyz[1], mp[xyz[1]]}};
}

pair <pii, pii> query(ll tl, ll tr, ll v, ll l, ll r){
    if(tl >= l && tr <= r){
        return {{mx[v], mxf[v]}, {smx[v], smxf[v]}};
    }

    if(tr < l || tl > r){
        return {{0, 0}, {0, 0}};
    }

    ll mid = (tl + tr) / 2;

    pair <pii, pii> q1 = query(tl, mid, 2 * v + 1, l, r);
    pair <pii, pii> q2 = query(mid + 1, tr, 2 * v + 2, l, r);

    return process(q1, q2);
}

void solve() {

    memset(mx, 0, sizeof(mx));
    memset(mxf, 0, sizeof(mxf));
    memset(smx, 0, sizeof(smx));
    memset(smxf, 0, sizeof(smxf));

    ll n, q;
    cin >> n >> q;

    read(a, i, n);

    for(ll i = 0; i < n; ++i){
        update(0, n - 1, 0, i, a[i]);
    }

    while(q--){
        ll t;
        cin >> t;

        if(t == 1){
            ll p, x;
            cin >> p >> x;

            --p;

            update(0, n - 1, 0, p, x);
        }
        else{
            ll l, r;
            cin >> l >> r;

            --l, --r;

            pair <pii, pii> q1 = query(0, n - 1, 0, l, r);
            cout << (q1.ss.ff == 0? 0: q1.ss.ss) << "\n";
        }
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}