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

        vector <int> preXOR(n);
        preXOR[0] = a[0];

        for(int i = 1; i < n; ++i){
            preXOR[i] = preXOR[i - 1] ^ a[i];
        }

        // print(preXOR, n);

        vector <int> vc(512, 0);
        vc[0] = 1;
        int ans = 0;

        for(int i = 255; i >= 0; --i){

            for(int j = 0; j < 256; ++j){
                vc[j] = 0;
            }
            vc[0] = 1;


            for(int j = 0; j < n; ++j){
                // Check if making xor = i possible

                // if(i == 14){
                //     cout << j << " " << preXOR[j] << " " << (preXOR[j] ^ i);
                //     cout << "\n"; 
                // }

                if(vc[preXOR[j] ^ i] == 1){

                    ans = i;
                    break;
                }

                vc[preXOR[j]] = 1;
            }

            if(ans != 0) break;
        }

        cout << ans << "\n";
    }
    
    return 0;
}