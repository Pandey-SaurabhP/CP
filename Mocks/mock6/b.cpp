
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long  ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){
//    fast();

    vector <int> a(8);
    read(a, 8);

    bool ok = 1;

    for(int i = 0; i < 9; ++i){
        if(a[i] == 9){
            ok = 0;
            break;
        }
    }

    if(ok) cout << "S";
    else cout << "F";

    return 0;
}






