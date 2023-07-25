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
        ll x, y;
        cin >> x >> y;

        if(x % 2 == 1){
            cout << "NO\n";
        }
        else{

            ll mult = x / 2;

            if(x * mult == y){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }


    }
    
    return 0;
}