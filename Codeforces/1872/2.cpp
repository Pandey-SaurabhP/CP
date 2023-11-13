
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

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> d(n), s(n);
        vector <ll> traps(2001, 2001);

        for(ll i = 0; i < n; ++i){
            cin >> d[i] >> s[i];
            traps[d[i]] = min(traps[d[i]], s[i]);
        }

//        print(traps, 10);


        ll start = 1;
        ll mx = 2001;

        for(ll i = 1; i < 2001; ++i){
            if(i == mx) break;
            mx = min(mx, i + ((traps[i] - 1) / 2));
            if(mx == i) break;

        }

        cout << mx << "\n";
    }

    return 0;
}



