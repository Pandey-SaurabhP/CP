// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

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

        if(n <= 2){
            cout << 0 << "\n";
            continue;
        }
        if(n % 2 == 1){
            n /= 2;
            --n;

            cout << (3 * n) + 2 << "\n"; 
        }
        else{
            n /= 2;
            --n;

            cout << (3 * n) << "\n";
        }
    }
    
    return 0;
}