#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
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
        ll n, k;
        cin >> n >> k;

        if(n <= k){
            cout << 1 << "\n";
            continue;
        }
        else{

            ll cnt = 0ll;
            bool ok = 0ll;

            for(ll i = (1ll << 31ll); i >= 2; i >>= 2){
                if(n >= i){
                    while(n >= i){
                        ++cnt;
                        n -= i;

                        if(n <= k){
                            break;
                        }
                    }
                }

                if(n <= k) break;
            }

            if(n == 0){
                cout << cnt << "\n";
            }
            else if(n <= k){
                cout << cnt + 1 << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}

