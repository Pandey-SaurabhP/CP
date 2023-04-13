// 5 2 3 7 8 9
// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll segTree[1000005];

void update(ll l, ll r, ll i, ll x, ll v){

    if(l == r){
        segTree[i] = v;
        return;
    }

    ll mid = (l + r) / 2;

    if(mid >= x) update(l, mid, 2 * i + 1, x, v);
    else{
        update(mid + 1, r, 2 * i + 2, x, v);
    }

    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
}

void build(ll l, ll r, ll i, vector <ll> &a, ll &n){

    if(l == r){
        segTree[i] = a[l];
        return;
    }

    ll mid = (l + r) / 2;

    build(l, mid, 2 * i + 1, a, n);
    build(mid + 1, r, 2 * i + 2, a, n);

    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2]; 
}

ll query(ll l, ll r, ll i, ll lll, ll rr){

    if(r < lll || l > rr) return 0;

    if(l >= lll && r <= rr){
        return segTree[i];
    }

    ll mid = (l + r) / 2;

    return query(l, mid, 2 * i + 1, lll, rr) + query(mid + 1, r, 2 * i + 2, lll, rr);
}


int main(){

    // fast();
    for(ll i = 0; i < 1000005; ++i){
        segTree[i] = 0;
    }

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    read(a, n);

    build(0, n - 1, 0, a, n);

    // print(segTree, 15);

    while(m--){
        ll type;
        cin >> type;

        if(type == 1){
            ll i, v;
            cin >> i >> v;

            update(0, n - 1, 0, i, v);

            // print(segTree, 10);
        }
        else{
            ll l, r;
            cin >> l >> r;

            cout << query(0, n - 1, 0, l, r - 1) << "\n";
        }
    }
    
    return 0;
}