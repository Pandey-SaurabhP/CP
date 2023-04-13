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
        int x, y;
        cin >> x >> y;

        if(x - y >= 2){
            cout << "CHEF\n";
        } 
        else if(y - x >= 2){
            cout << "CHEFINA\n";
        }
        else if(x == y){
            if(x % 2 == 0){
                cout << "CHEFINA\n";
            }
            else{
                cout << "CHEF\n";
            }
        }
        else{
            if(min(x, y) % 2 == 0){
                cout << "CHEFINA\n";
            }
            else{
                cout << "CHEF\n";
            }
        }
    }
    
    return 0;
}