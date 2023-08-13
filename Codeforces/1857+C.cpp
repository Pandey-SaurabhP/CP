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

        vector <int> b((n * (n - 1)) / 2);
        read(b, (n * (n - 1)) / 2);

        sort(b.begin(), b.end());

        vector <int> a(n);
        
        int x = n - 2;
        int id = n - 2;

        for(int i = 0; i < n; ++i){
            // cout << id << " ";
            a[i] = b[id];

            id += x;
            --x;
        }

        // cout << "\n";

        print(a, n);
    }
    
    return 0;
}