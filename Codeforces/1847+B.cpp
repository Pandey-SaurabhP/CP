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
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        int bestAns = a[0];

        for(int i = 0; i < n; ++i){
            bestAns &= a[i];
        }

        if(bestAns != 0){
            cout << 1 << "\n";
        }
        else{

            int ans = 0;

            int cb = a[0];
            for(int i = 0; i < n; ++i){
                cb &= a[i];

                if(cb == 0){
                    ++ans;

                    if(i + 1 < n){
                        cb = a[i + 1];
                    }
                }
            }

            cout << ans << "\n";
        }
    }
    
    return 0;
}