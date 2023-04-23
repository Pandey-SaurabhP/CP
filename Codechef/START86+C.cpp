
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
        ll n, x;
        cin >> n >> x;

        vector <ll> a(n);
        read(a, n);

        vector <ll> sb(40, 0); 

        for(ll i = 0; i < n; ++i){
            string tmp;
            ll tx = a[i];

            while(tx){
                tmp += (tx % 2) + '0';
                tx /= 2;
            }
            while(tmp.size() != 35){
                tmp += '0';
            }

            // cout << a[i] << " : " << tmp << "\n";

            for(ll j = 0; j < tmp.size(); ++j){
                if(tmp[j] == '0'){
                    sb[j] = 1;
                }
            }
        }

        ll ans2 = 0;

        for(ll i = 0; i < 35; ++i){
            // if sabme set then ok

            bool ok = 1;

            for(ll j = 0; j < n; ++j){
                if((a[j] & (1ll << i)) == 0){
                    ok = 0;
                    break;
                }
            }

            if(ok){
                ans2 |= (1ll << i);
            }
        }

        ll tx = 0;

        for(ll i = 34ll; i >= 0; --i){
            if((ans2 & (1ll << i)) != 0){
                tx |= (1ll << i);

                if(tx > x){
                    tx ^= (1ll << i);
                }
            }
        }

        ans2 = tx;

        // print(sb, 35);

        ll ans = 0;

        for(ll i = 0; i < 35; ++i){
            if(sb[i] == 1){
                if((x & (1ll << i)) != 0){
                    ans = max(ans, x ^ (1 << i));
                }
                else{
                    // Either already set
                    if((1ll << i) < x){    
                        // cout << "Running 2! : " << i << " "  << x << "\n";
                        ans = x;
                        break;
                    }
                }
            }
        }

        // cout << ans << " " << ans2 << " ";
        cout << max(ans, ans2) << "\n";
    }
    
    return 0;
}