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

ll getPower(ll base, ll exp){

    ll ans = 1;

    while(exp){
        ans *= base;
        --exp;
    }

    return ans;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll a, b, c, k;;
        cin >> a >> b >> c >> k;

        bool fnd = 0;

        for(ll i = getPower(10, a - 1); i < getPower(10, a); ++i){

            ll l = max(getPower(10, b - 1), getPower(10, c - 1) - i);
            ll r = min(getPower(10, b) - 1, getPower(10, c) - i - 1);

            if(l > r) continue;

            

            ll valid = r - l + 1; // Inclusive
            
            if(k - valid <= 0){
                // Print kth value then
                cout << i << " + " << l + k - 1 << " = " << i + l + k - 1 << "\n";
                fnd = 1;
                break;
            }

            k -= valid;
        }

        if(!fnd){
            cout << -1 << "\n";
        }

    }
    
    return 0;
}