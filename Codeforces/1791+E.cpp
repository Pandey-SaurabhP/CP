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

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        ll cntNeg = 0;

        for(ll i = 0; i < n; ++i){
            if(a[i] < 0){
                cntNeg++;
            }
        }

        ll sm = 0;
        ll mn = abs(a[0]);
        for(ll i = 0; i < n; ++i){
            sm += abs(a[i]);
            mn = min(mn, abs(a[i]));
        }

        if(cntNeg % 2 == 0){
            cout << sm << "\n";
        }
        else{
            cout << sm - (2 * mn) << "\n";
        }


    }
    
    return 0;
}