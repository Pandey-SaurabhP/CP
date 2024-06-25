// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <ll> segTree(mxn, 0);

void update(ll id, ll val, ll l, ll r, ll sid){

    if(l == r){
        segTree[sid] = val;
        return;
    }

    ll mid = (l + r) / 2;

    if(mid >= id){
        update(id, val, l, mid, 2 * sid + 1);
    }
    else{
        update(id, val, mid + 1, r, 2 * sid + 2);
    }

    segTree[sid] = max(segTree[2 * sid + 1], segTree[2 * sid + 2]);
}

ll qry(ll ql, ll qr, ll l, ll r, ll sid){

    if(l >= ql && r <= qr){
        return segTree[sid];
    }
    else if(r < ql || l > qr){
        return 0;
    }
    else{
        ll mid = (l + r) / 2;
        return max(qry(ql, qr, l, mid, 2 * sid + 1), qry(ql, qr, mid + 1, r, 2 * sid + 2));
    }

    return -1;
}

int main(){

    // fast();

    ll n;
    cin >> n;

    vector <ll> a(n);
    vector <ll> b(n);

    read(a, n);
    read(b, n);

    ll glAns = 0;

    for(ll i = 0; i < n; ++i){
        ll ans = b[i];

        ans += qry(0, a[i] - 1, 0, n - 1, 0);
        update(a[i], ans, 0, n - 1, 0);

        glAns = max(ans, glAns);
    }

    cout << glAns;
    
    return 0;
}