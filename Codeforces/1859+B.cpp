#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <pair <ll, ll>> vc;


        for(ll i = 0; i < n; ++i){
            ll m;
            cin >> m;

            vector <ll> tmp(m);
            read(tmp, m);
            sort(tmp.begin(), tmp.end());

            vc.push_back({tmp[0], tmp[1]});
        }

        ll sm = 0;
        ll mn = INT_MAX;
        ll mn2 = INT_MAX;

        for(ll i = 0; i < n; ++i){
            sm += vc[i].second;
            mn = min(mn, vc[i].first);
            mn2 = min(mn2, vc[i].second);
        }

        cout << sm + mn - mn2 << "\n";
    }
    
    return 0;
}