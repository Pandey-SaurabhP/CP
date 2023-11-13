#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

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

    segTree[i] = segTree[2 * i + 1] & segTree[2 * i + 2];
}

void build(ll l, ll r, ll i, vector <ll> &a, ll &n){

    if(l == r){
        segTree[i] = a[l];
        return;
    }

    ll mid = (l + r) / 2;

    build(l, mid, 2 * i + 1, a, n);
    build(mid + 1, r, 2 * i + 2, a, n);

    segTree[i] = segTree[2 * i + 1] & segTree[2 * i + 2];
}

ll query(ll l, ll r, ll i, ll lll, ll rr){

    if(r < lll || l > rr) return (1ll << 32) - 1;

    if(l >= lll && r <= rr){
        return segTree[i];
    }

    ll mid = (l + r) / 2;

    return query(l, mid, 2 * i + 1, lll, rr) & query(mid + 1, r, 2 * i + 2, lll, rr);
}



int main(){
//    initCode();

     fast();

//    sieve();
//
//    cout << "Hello\n";
//    cout << primeList.size() << "\n";

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        build(0, n - 1, 0, a, n);

//        for(ll i = 0; i < 4 * n; ++i){
//            cout << segTree[i] << " ";
//        }
//        cout << "\n";

//        cout << query(0, n - 1, 0, 0, 1) << "\n";

        ll q;
        cin >> q;

        while(q--){
            ll l, x;
            cin >> l >> x;

            --l;

            ll lo = l;
            ll hi = n - 1;

            ll ans = -1;



            while(lo <= hi){
                ll mid = (lo + hi) / 2;


                if(query(0, n - 1, 0, l, mid) >= x){
                    ans = mid;
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }

            if(ans == -1){
                cout << ans << " ";
            }
            else cout << ans + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}


