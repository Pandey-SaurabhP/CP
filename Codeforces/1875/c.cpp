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
        ll n, m;
        cin >> n >> m;

        ll start = n;

        n %= m;

        if(n == 0ll){
            cout << 0 << "\n";
            continue;
        }

        while(n < m){
            n *= 2;
        }

        if(__gcd(n, m) == 1){
            cout << -1 << "\n";
        }
        else{
            ll cnt = 0ll;
            n = start;
            n %= m;

            int ops = 0;

            while(n != 0ll){
                ++ops;
                cnt += n;
                n *= 2;

                n %= m;

                if(ops > 1000){
                    cnt = -1;
                    break;
                }
            }

            cout << cnt << "\n";
        }
    }

    return 0;
}



