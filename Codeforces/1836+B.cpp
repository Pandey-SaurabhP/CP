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
        ll n, k, g;
        cin >> n >> k >> g;

        ll totalCoin = k * g;
        ll perHead;

        if(g % 2 == 0){
            perHead = (g / 2) - 1;
        }
        else{
            perHead = g / 2;
        }

        // cout << perHead << "\n";


        if(perHead * n >= totalCoin){
            ll ans = k * g;
            cout << ans << "\n";
        }
        else{
            totalCoin = k * g;
            totalCoin -= (perHead) * (n - 1ll);

            // cout << totalCoin << "\n";

            ll left = totalCoin;

            ll expense = left / g;
            left -= expense * g;

            // cout << left << " " << expense << "\n";


            if(g % 2 == 0){
                if(left >= (g / 2)){
                    ++expense;
                }
            }
            else{
                if(left > (g / 2)){
                    ++expense;
                }
            }

            expense *= g;

            ll ans = (k * g) - expense;

            cout << ans << "\n";
        }

    }
    
    return 0;
}