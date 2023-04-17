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
        int a, b;
        cin >> a >> b;

        int ans = INT_MAX;

        for(int k = 1; k <= min(100000, max(a, b)); ++k){
            int localAns = (a + k - 1) / k;
            localAns += (b + k - 1) / k;
            localAns += (k - 1);

            ans = min(ans, localAns);
        }

        cout << ans << "\n";
    }
    
    return 0;
}