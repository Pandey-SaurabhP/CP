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

    // vector <ll> memo(mxn, -1);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        // if(memo[n] != -1){
        //     if(memo[n] == 1){
        //         cout << "YES\n";
        //     }
        //     else{
        //         cout << "NO\n";
        //     }
        // }

        bool ok = 0;

        // ll finalk = 2;

        for(ll k = 2; (1ll + k + (k * k)) <= n; ++k){
            
            // finalk = k;

            ll initial = 1;
            initial += k;

            ll plus = k * k;

            while(initial <= n){
                initial += plus;
                plus *= k;

                if(initial == n){
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        // cout << finalk << "\n";

        // memo[n] = ok;

        if(ok) cout << "YES\n";
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}