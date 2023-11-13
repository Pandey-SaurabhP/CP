
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

    ll t;
    cin >> t;

    while(t--){
        int a, b, c;
        cin >> a >> b >> c;

        if(a > b){
            swap(a, b);
        }

        if((a + b) % 2 == 0){
            int rq = (a + b) / 2;
            cout << (rq - a + c - 1) / c << "\n";
        }
        else{
            int rq = (a + b) / 2;
            ++rq;
            cout << (rq - a + c - 1) / c << "\n";
        }

    }

    return 0;
}




