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

    int t;
    cin >> t;

    while(t--){
        int n, m, k, h;
        cin >> n >> m >> k >> h;

        vector <int> a(n);
        read(a, n);

        for(int i = 0; i < n; ++i){
            a[i] += k;
        }

        if(m == 1){
            cout << 0 << "\n";
            continue;
        }

        h += k;

        

        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(abs(a[i] - h) % k == 0){
                ++ans;

                int x = min(a[i], h) + (k * m);
                int y = max(a[i], h);
                
                // cout << a[i] << " " << x << " " << y << "\n";
                if(x <= y || a[i] == h){
                    --ans;
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}