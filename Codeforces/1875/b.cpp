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


int main(){
    fast();
    ll t;
    cin >> t;

    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;

        vector <ll> a(n);
        vector <ll> b(m);

        read(a, n);
        read(b, m);

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if(k % 2 == 1){
            if(a[0] < b[m - 1]) swap(a[0], b[m - 1]);
        }
        else if(k % 2 == 0){
            if(a[0] < b[m - 1]) swap(a[0], b[m - 1]);

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            if(b[0] < a[n - 1]) swap(b[0], a[n - 1]);
        }

        ll ans = 0;
        for(auto it : a){
            ans += it;
        }

        cout << ans << "\n";
    }

    return 0;
}




