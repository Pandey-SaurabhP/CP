// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << endl; } else { cout << a[i] << ' '; }

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

        vector <int> sb(32, 0);

        vector <int> tmp = a;

        for(int i = 0; i < n; ++i){
            int pos = 0;
            while(tmp[i]){
                if(tmp[i] & 1){
                    sb[pos]++;
                }

                tmp[i] >>= 1;
                ++pos;
            }   
        }

        bool pos = 1;

        for(int i = 0; i < 32; ++i){
            if(n % 2 == 0){
                if(sb[i] % 2 == 1){
                    pos = 0;
                    break;
                }
            }

            // cout << sb[i] << " ";
        }
        // cout << "\n";

        if(pos){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}