
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
        int n;
        cin >> n;

        n *= 2;

        vector <double> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        int i = 0;
        int j = n - 1;

        double req = (a[0] + a[n - 1]) / 2.0;
        bool ok = 1;

        while(i < j){
            double cur = (a[i] + a[j]) / 2.0;
            if(cur != req){
                ok = 0;
                break;
            }
            ++i; --j;
        }

        if(ok){
            cout << "PERFECT\n";
        }
        else{
            cout << "IMBALANCED\n";
        }
    }

    return 0;
}




