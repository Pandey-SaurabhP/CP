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
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        int ans = INT_MAX;

       for(int i = 0; i < n; ++i){
        // Let Alice pick the current element
            int lc = INT_MIN;

            if(i - 1 >= 0){
                lc = max(lc, abs(a[i] - a[i - 1]));
            }
            if(i + 1 < n){
                lc = max(lc, abs(a[i + 1] - a[i]));
            }

            if(lc != INT_MIN) ans = min(ans, lc);
       }

       cout << ans << "\n";
    }

    
    return 0;
}