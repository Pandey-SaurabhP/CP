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

int segTree[1000005];

void build(int l, int r, int i, vector <int> &a, int &n){

    if(l == r){
        segTree[i] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(l, mid, 2 * i + 1, a, n);
    build(mid + 1, r, 2 * i + 2, a, n);

    segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

void update(int l, int r, int i, int id, int val){

    if(l == r){
        segTree[i] = val;
        return;
    }

    int mid = (l + r) / 2;

    if(mid < id){
        update(mid + 1, r, 2 * i + 2, id, val);
    }
    else{
        update(l, mid, 2 * i + 1, id, val);
    }

    segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

int query(int l, int r, int i, int ll, int rr){

    if(l > rr || r < ll) return INT_MAX;

    if(l >= ll && r <= rr){
        return segTree[i];
    }

    int mid = (l + r) / 2;

    return min(query(l, mid, 2 * i + 1, ll, rr), query(mid + 1, r, 2 * i + 2, ll, rr));

}

int main(){

    // fast();
    for(int i = 0; i < 1000005; ++i){
        segTree[i] = 0;
    }

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    read(a, n);

    build(0, n - 1, 0, a, n);

    // print(segTree, 10);

    while(m--){
        int type;
        cin >> type;

        if(type == 1){
            int i, v;
            cin >> i >> v;

            update(0, n - 1, 0, i, v);

            // print(segTree, 10);
        }
        else{
            int l, r;
            cin >> l >> r;

            cout << query(0, n - 1, 0, l, r - 1) << "\n";
        }
    }
    
    return 0;
}