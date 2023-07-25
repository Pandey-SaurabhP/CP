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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        vector <int> id(n + 1);

        for(int i = 0; i < n; ++i){
            id[a[i]] = i;
        }

        int ans = 1;

        int mn = id[n];
        int mx = id[n];

        for(int i = n; i > 1; --i){
            mn = min(mn, id[i]);
            mx = max(mx, id[i]);

            // cout << i << " " << mn << " " << mx << " " << mx - mn + 1 << " " << n - i + 1 << "\n";
            if((mx - mn + 1 ) == (n - i + 1)){
                ans = max(ans, n - i + 1);
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}