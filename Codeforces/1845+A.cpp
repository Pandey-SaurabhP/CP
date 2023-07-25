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
        int n, k, x;
        cin >> n >> k >> x;

        if(x != 1){
            cout << "YES\n" << n << "\n";
            for(int i = 0; i < n; ++i){
                cout << 1 << " ";
            }
            cout << "\n";
        }
        else{

            if(n % 2 == 0){
                if(k >= 2){
                    cout << "YES\n";

                    cout << n / 2 << "\n";

                    for(int i = 0; i < n / 2; ++i){
                        cout << 2 << " ";
                    }
                    cout << "\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                if(k >= 3){
                    cout << "YES\n";
                    cout << n / 2 << "\n";

                    for(int i = 0; i < (n / 2) - 1; ++i){
                        cout << 2 << " ";
                    }
                    cout << 3 << "\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    
    return 0;
}