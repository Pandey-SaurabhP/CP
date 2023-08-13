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

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        if(n == 1){
            cout << "NO\n";
            continue;
        }

        ll sm = accumulate(a.begin(), a.end(), 0ll);

        sm -= n;

        if(sm == 0){
            cout << "NO\n";
        }
        else{
            ll oneCnt = 0;
            for(auto it : a){
                if(it == 1) ++oneCnt;;
            }

            if(sm - oneCnt < 0){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
    }
    
    return 0;
}