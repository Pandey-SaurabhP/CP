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

        int n;
        cin >> n;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if((i + j) % 2 == 0){
                    cout << "W";
                }
                else{
                    cout << "B";
                }
            }

            cout << "\n";
        }

    
    return 0;
}