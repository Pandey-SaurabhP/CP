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
        ll a, b;
        cin >> a >> b;

        ll n, m;
        cin >> n >> m;

        ll tr = (m * n) / (m + 1);
        ll buy = (tr / m) * m;
        ll free = tr / m;

        // cout << tr << " : " << a * tr << " " << (tr / m) << " : " << (n - bought) * min(a, b) << "\n"; 
        // cout << tr << " " << buy << " " << free << " : " << n - (buy + free) << "\n";

        cout << min(min(n * a, n * b), (a * buy) + ((n - (buy + free)) * min(a, b))) << "\n";
    }
    
    return 0;
}