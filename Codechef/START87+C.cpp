// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 998244353;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll fastPower(ll b, ll e){

    ll ans = 1ll;

    while(e){
        if(e & 1){
            ans *= b;
            --e;
        }

        ans %= mod;

        b *= b;
        b %= mod;

        e /= 2;
    }

    return ans;
}

int main(){

    // cout << fastPower(4, 5) << "\n";
    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        for(ll i = 0; i < n; ++i){
            --a[i];
        }

        // print(a, n);

        ll cnt = 0;

        ll x = 0;
        if(a[x] == x){
            while(x < n && a[x] == x){
                ++x;
                ++cnt;
            }
        }

        ll ans;
    
        if(x == n){
            ans = fastPower(2, cnt);
            cout << (ans - 1 + mod) % mod << "\n";
            continue;
        }
        else{
            ll mxVal = a[0];
            
            for(ll i = x; i < n; ++i){

                mxVal = max(mxVal, a[i]);

                // cout << i << " " << mxVal << "\n";

                if(i == mxVal){
                    // cout << "Running this!" << i + 1 << " ";

                    ll j = i + 1;

                    while(j < n && a[j] == j){
                        ++cnt;
                        ++j;

                        mxVal = max(mxVal, a[j]);
                    }

                    // cout << j - 1 << "\n";

                    i = j - 1;
                }
            }

            ans = fastPower(2, cnt);
            cout << ans % mod << "\n";

            // cout << ans << "\n";
        }

        
    }
    
    return 0;
}