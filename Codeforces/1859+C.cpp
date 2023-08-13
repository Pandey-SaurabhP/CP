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

        vector <ll> a(n);
        for(ll i = 0; i < n; ++i){
            a[i] = i + 1;
        }

        ll mx = 0;

        for(ll i = 0; i < n; ++i){
            // Reverse from ith position
            vector <ll> b(n);

            for(ll j = 0; j < i; ++j){
                b[j] = a[j]; 
            }

            for(ll j = i; j < n; ++j){
                b[j] = a[n - j + i - 1];
            }

            // prll(b, n);

            ll sm = 0;
            ll mx2 = 0;


            for(ll j = 0; j < n; ++j){
                sm += (b[j] * (j + 1));
                mx2 = max(mx2, b[j] * (j + 1));
            }

            mx = max(mx, sm - mx2);
        }

        cout <<  mx << "\n";
    }
    
    return 0;
}