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

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> b(n);
        read(b, n);

        ll q = 0;
        ll p = 0;

        for(ll i = 0; i < n; ++i){
            if(b[i] == -1){
                q += (i + 1);
            }
            else{
                p += (i + 1);
            }
        }

        cout << abs(p - q) << "\n";
    }
    
    return 0;
}