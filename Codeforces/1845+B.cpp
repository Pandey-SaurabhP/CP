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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int x, y;
        cin >> x >> y;

        int xa, ya, xb, yb;

        cin >> xa >> ya;
        cin >> xb >> yb;

        int ans = 1;

        if(xa > xb) swap(xa, xb);

        if(x <= xa){
            ans += (xa - x);
        }
        else if(x >= xb){
            ans += (x - xb);
        }
        
        if(ya > yb){
            swap(ya, yb);
        }

        if(y <= ya){
            ans += (ya - y);
        }
        else if(y >= yb){
            ans += (y - yb);
        }
        cout << ans << "\n";
    }
    
    return 0;
}