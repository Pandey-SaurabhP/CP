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

        string ans = "1";
        int lst = a[0]; 

        bool broken = 0;

        for(int i = 1; i < n; ++i){
            if(!broken){
                if(a[i] >= a[i - 1]){
                    ans += "1";
                    lst = a[i];
                }
                else{
                    if(a[i] <= a[0]){
                        lst = a[i];
                        ans += "1";
                        broken = 1;
                    }
                    else{
                        ans += "0";
                    }
                }
            }
            else{
                if(a[i] >= lst && a[i] <= a[0]){
                    ans += "1";
                    lst = a[i];
                }
                else{
                    ans += "0";
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}