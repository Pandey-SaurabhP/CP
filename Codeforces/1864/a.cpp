
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

//    fast();

    ll t;
    cin >> t;

    while(t--){

        ll x, y, n;
        cin >> x >> y >> n;

        ll reqGap = (n * (n - 1)) / 2;

        if(y - x >= reqGap){
            vector <ll> ans(n);
            ans[0] = x;
            ans[n - 1] = y;

            ll gp = 1;

            for(ll i = n - 2; i >= 1; --i){
                ans[i] = ans[i + 1] - gp;
                ++gp;
            }

            print(ans, n);
        }
        else{
            cout << -1 << "\n";
        }
    }

    return 0;
}


