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

    vector <ll> fib;

    fib.push_back(0);
    fib.push_back(1);

    for(ll i = 2; i < 50; ++i){
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }

    // prll(fib, 100);

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        if(k > 50){
            cout << 0 << "\n";
            continue;
        }

        if(k == 1 || k == 2){
            cout << 1 << "\n";
            continue;
        }
        else{
            ll ans = 0;

            for(ll a0 = 0; a0 <= n; ++a0){
                ll num = n - (fib[k - 2] * a0);

                if(num < 0) break;

                if(num % fib[k - 1] == 0){
                    num /= fib[k - 1];

                    if(num >= a0){
                        ++ans;
                    }
                }
            }

            cout << ans << "\n";
        }
    }
    
    return 0;
}