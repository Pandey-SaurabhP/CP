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

        if(n % 2 == 1){
            cout << -1 << "\n";
        }
        else{

            for(int i = 0; i < n; i += 2){
                cout << i + 2 << " " << i + 1 << " ";
            }

            cout << "\n";
        }
    }
    
    return 0;
}