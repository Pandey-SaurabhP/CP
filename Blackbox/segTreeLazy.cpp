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

class segmentTreeL{
public:
    vector <ll> segTree;
    vector <ll> lazy;
    ll mxn;

    segmentTreeL(){
        segTree.resize(1000005);
        lazy.resize(1000005);
        mxn = 1000005;
    }

    segmentTreeL(ll n){
        segTree.resize(4 * n);
        lazy.resize(4 * n);
        mxn = 4 * n;
    }

    void zero(){
        for(int i = 0; i < mxn; ++i){
            segTree[i] = 0;
        }
    }

    void build(ll l, ll r, ll i, vector <ll> &a){

        if(l == r){
            segTree[i] = a[l];
            return;
        }

        ll mid = (l + r) / 2;

        build(l, mid, 2 * i + 1, a);
        build(mid + 1, r, 2 * i + 2, a);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    void rangeUpdate(ll l, ll r, ll i, ll ul, ll ur, ll uval){

        if(l >= ul && r <= ur){
            // Completely inside
            segTree[i] += uval;
            lazy[2 * i + 1] += uval;
            lazy[2 * i + 2] += uval;

            return;
        }

        if(l > ur || r < ul){
            return;
        }

        int mid = (l + r) / 2;

        rangeUpdate(l, mid, 2 * i + 1, ul, ur, uval);
        rangeUpdate(mid + 1, r, 2 * i + 2, ul, ur, uval);

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    ll pointQuery(ll l, ll r, ll i, ll ui){
        if(l == r){
            return segTree[i] + lazy[i];
        }

        segTree[i] += lazy[i];
        lazy[2 * i + 1] = lazy[i];
        lazy[2 * i + 2] = lazy[i];
        lazy[i] = 0;

        int mid = (l + r) / 2;

        if(mid >= ui){
            return pointQuery(l, mid, 2 * i + 1, ui);
        }
        else{
            return pointQuery(mid + 1, r, 2 * i + 2, ui);
        }
    }
};

int main(){

    fast();

    ll n, m;
    cin >> n >> m;

    // vector <ll> a(n);
    // read(a, n);

    segmentTreeL sT(n);
    sT.zero();
    // sT.build(0, n - 1, 0, a);

    while(m--){
        int type;
        cin >> type;

        if(type == 1){
            int l, r, v;
            cin >> l >> r >> v;

            sT.rangeUpdate(0, n - 1, 0, l, r - 1, v);
        }
        else{
            int i;
            cin >> i;

            cout << sT.pointQuery(0, n - 1, 0, i) << "\n";
        }
    }
    
    return 0;
}