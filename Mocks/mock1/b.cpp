
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
        ll n, m;
        cin >> n >> m;

        vector <ll> a(n);
        read(a, n);

        vector <ll> b(n);
        read(b, n);

        vector <ll> maxPre(n);
        maxPre[0] = max(a[0], 0ll);

        for(ll i = 1; i < n; ++i){
            maxPre[i] = max(0ll, maxPre[i - 1] + a[i]);
        }

        vector <ll> maxPost(n);
        maxPost[n - 1] = max(0ll, a[n - 1]);

        for(ll i = n - 2; i >= 0; --i){
            maxPost[i] = max(0ll, maxPost[i + 1] + a[i]);
        }

//        print(maxPre, n);
//        print(maxPost,n);
        ll ans = 0;
        for(ll i = 0; i < n; ++i){
            ll cur = max(a[i] + (b[i] * m), a[i]);

            if(i - 1 >= 0){
                cur += maxPre[i - 1];
            }
            if(i + 1 < n){
                cur += maxPost[i + 1];
            }

            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }

    return 0;
}




