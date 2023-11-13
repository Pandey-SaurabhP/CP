
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

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

//    fast();

    ll t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        while(1){
            if(a == 0 || b == 0){
                break;
            }

            if(a > b){
                a -= (((a - b) / b) + 1) * b;
            }
            else if(b > a){
                b -= (((b - a) / a) + 1) * a;
            }
            else{
                a -= b;
            }

//            cout << a << " " << b << "\n";
        }

        if(a > 0){
            cout << a << "\n";
        }
        else{
            cout << b << "\n";
        }
    }

    return 0;
}



