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

class segmentTree{
public:
 
    vector <ll> segTree;
 
    segmentTree(){
        segTree.resize(1000005);

        for(int i = 0; i < segTree.size(); ++i){
            segTree[i] = 0;
        }
    }
 
    segmentTree(ll n){
        segTree.resize(4 * n);

        for(int i = 0; i < 4 * n; ++i){
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

    // fast();

    segmentTree sg(10);
    sg.pointUpdate(0, 9, 0, 0, 1);
    sg.pointUpdate(0, 9, 0, 2, 1);
    sg.pointUpdate(0, 9, 0, 3, 1);
    sg.pointUpdate(0, 9, 0, 5, 1);
    sg.pointUpdate(0, 9, 0, 6, 1);
    sg.pointUpdate(0, 9, 0, 8, 1);

    for(int i = 0; i < 10; ++i){
        cout << sg.rangeQuery(0, 9, 0, i, i) << " ";
    }
    
    return 0;
}