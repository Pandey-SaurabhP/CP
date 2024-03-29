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

class segmentTree{
public:
    vector <ll> segTree;

    segmentTree(){
        segTree.resize(1000005);
    }

    segmentTree(ll n){
        segTree.resize(4 * n);
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

    void pointUpdate(ll l, ll r, ll i, ll uidx, ll uval){

        if(l == r){
            segTree[i] = uval;
            return;
        } 

        ll mid = (l + r) / 2;

        if(mid >= uidx){
            pointUpdate(l, mid, 2 * i + 1, uidx, uval);
        }
        else{
            pointUpdate(mid + 1, r, 2 * i + 2, uidx, uval);
        }

        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    ll rangeQuery(ll l, ll r, ll i, ll ul, ll ur){

        if(l >= ul && r <= ur){
            return segTree[i];
        }

        if(r < ul || l > ur){
            return 0;
        }

        ll mid = (l + r) / 2;

        ll a1 = rangeQuery(l, mid, 2 * i + 1, ul, ur);
        ll a2 = rangeQuery(mid + 1, r, 2 * i + 2, ul, ur);

        return a1 + a2;
    }
};

int main(){

    fast();

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    read(a, n);

    segmentTree sT(n);
    sT.build(0, n - 1, 0, a);

    while(m--){
        ll type;
        cin >> type;

        if(type == 1){
            ll i, v;
            cin >> i >> v;

            sT.pointUpdate(0, n - 1, 0, i, v);        
        }
        else{
            ll l, r;
            cin >> l >> r;

            cout << sT.rangeQuery(0, n - 1, 0, l, r - 1) << "\n";
        }
    }
    
    return 0;
}