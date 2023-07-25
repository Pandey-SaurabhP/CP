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
         int n;
         cin >> n;

         vector <int> a(n);
         read(a, n);

         int mnDiff = INT_MAX;


         for(int i = 1; i < n; ++i){
            mnDiff = min(mnDiff, a[i] - a[i - 1]);
         }

         if(mnDiff < 0){
            cout << 0 << "\n";
         }
         else{
            cout << 1 + ((mnDiff) / 2) << "\n";
         }
    }
    
    return 0;
}