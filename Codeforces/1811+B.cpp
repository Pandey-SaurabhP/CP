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

    int t;
    cin >> t;

    while(t--){
        ll n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >>x2 >> y2;

        ll r1 = min(x1, n - x1 + 1);
        ll r2 = min(x2, n - x2 + 1);

        r1 = min(r1, min(y1, n - y1 + 1));
        r2 = min(r2, min(y2, n - y2 + 1));

        cout << abs(r1 - r2) << "\n";
    }
    
    return 0;
}