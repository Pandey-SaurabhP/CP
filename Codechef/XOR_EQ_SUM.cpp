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

    // fast();

    ll t;
    cin >> t;

    while(t--){
        ll l, r;
        cin >> l >> r;

        ll ans = 0;

        if(l == 0){
            ll j = 1;
            for(j = 1; 1; j <<= 1){
                if(j > r){
                    break;
                }
            }

            cout << j << "\n";
        }
        else{

            for(ll i = 1; i <= 1000000; ++i){

                ll j;

                for(j = 1; 1; j <<= 1){
                    if(j > i){
                        j >>= 1;
                        break;
                    }
                }

                if((j <= r) && ((i ^ j) >= l)){
                    ++ans;
                }
            }

            cout << ans << "\n";
        }
    }
    
    return 0;
}