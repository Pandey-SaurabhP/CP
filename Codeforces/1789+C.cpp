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
        ll n, m;
        cin >> n >> m;

        vector <ll> a(n);
        read(a, n);

        vector <ll> cnt(n + m + 1, 0);

        for(ll i = 0; i < n; ++i){
            cnt[a[i]] = m + 1;
        }

        ll tmp = m;

        vector <int> vc;

        while(m--){
            ll p, v;
            cin >> p >> v;

            --p;

            cnt[a[p]] -= (m + 1);
            a[p] = v;
            cnt[a[p]] += (m + 1);
        }

        m = tmp;

        ll ans = 0;
        ll mx = (m * (m + 1)) / 2;

        for(ll i = 0; i < n + m + 1; ++i){

            if(cnt[i]){
                ans += mx;
                
                ll pr = m + 1 - cnt[i];
                ll cont = (pr * (pr - 1)) / 2;

                ans -= cont;
            }
        }

        cout << ans << "\n";

            
    }
    
    return 0;
}