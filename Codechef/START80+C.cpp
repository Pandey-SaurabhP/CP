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

        vector <ll> a(n);
        read(a, n);

        vector <ll> cnt(n + 1, 0);


        for(ll i = 0; i < n; ++i){
            if(a[i] <= n){
                ++cnt[a[i]];
            }
        }        

        ll ans = 0;
        ll mult = 1;

        for(ll i = 1; i <= n; ++i){
            if(cnt[i] == 0){
                break;
            }

            ans += (cnt[i] * mult);
            mult *= cnt[i];

            ans %= mod;
            mult %= mod;

            // cout << i << " " << cnt[i] << " " << ans << " " << mult << "\n"; 
        }

        cout << ans << "\n";
    }
    
    return 0;
}