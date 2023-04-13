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

        ll mSet = 1 << 20;
        ll ans = 0;

        int mR = a[0];

        bool ok = 0;
        for(int i = 0; i < n - 1; ++i){
            
            mR = max(mR, i + a[i]);

            if(mR == i){
                ok = 0;
                break;
            }
            if(mR >= n - 1){
                ok = 1;
            }
        }

        if(!ok){
            cout << "-1\n";
            continue;
        }

        vector <bool> discarded(n, 0);

        while(mSet){

            if((a[0] & mSet) | (a[n - 1] & mSet)){
                // Unavoidable in any case
                ans |= mSet;
                mSet >>= 1;
                continue;
            }

            vector <bool> tmp = discarded;

            for(int i = 1; i < n - 1; ++i){
                if(a[i] & mSet){
                    tmp[i] = 1;
                }
            }

            int mxReach = a[0];
            for(int i = 0; i < n - 1; ++i){
                if(!tmp[i]){
                    mxReach = max(mxReach, i + a[i]);
                }
                
                if(mxReach >= n - 1){
                    // Successful
                    discarded = tmp;
                    break;
                }

                if(i == mxReach){
                    // Current bit unavoidable
                    ans |= mSet;
                    break;
                }
            }

            mSet >>= 1;
        }

        cout << ans << "\n";
    }
    
    return 0;
}