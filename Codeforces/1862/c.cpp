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

        vector <ll> a(n);
        read(a, n);

        ll mx = a[0];
        for(ll i = 0; i < n; ++i){
            mx = max(mx, a[0]);
        }

        if(mx > n){
            cout << "NO\n";
            continue;
        }

        vector <ll> a2(n + 2, 0);

        for(ll i = 0; i < n; ++i){
            a2[a[i] + 1]--;
            a2[1] += 1;
        }

        vector <ll> h(n + 2, 0);
        for(ll i = 1; i < n + 2; ++i){
            h[i] = h[i - 1] + a2[i];
        }

//        print(h, n + 2);

        bool ok =1;
        for(ll i = 1; i < n + 1; ++i){
            if(h[i] != a[i - 1]){
                ok = 0;
            }
        }

        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
