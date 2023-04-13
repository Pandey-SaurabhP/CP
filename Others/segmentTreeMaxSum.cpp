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




int main(){

    // fast();
    for(ll i = 0; i < 1000005; ++i){
        segTree[i] = 0;
    }

    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, n);

    build(0, n - 1, 0, a, n);
    
    return 0;
}