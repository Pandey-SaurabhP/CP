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
        
        if(n == 1){
            cout << 1 << "\n";
        }
        else{
            if(n % 2 == 1){
                cout << "-1\n";
            }
            else{

                a[0] = n;

                int l = 1;
                int r = n - 1;

                for(int i = 1; i < n / 2; ++i){
                    a[i] = l;
                    a[n - i] = r;

                    ++l;
                    --r;
                }

                a[n / 2] = n / 2;
                
                print(a, n);
            }
        }
    }
    
    return 0;
}