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

int solve(int i, vector <bool> done, vector <pair <int, int>> &vc, int &n){
    
}

int main(){

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <pair <int, int>> vc;

        for(int i = 0; i < n; ++i){
            int x, y;
            cin >> x >> y;

            vc.push_back({x, y});
        }

        vector <bool> done(n, 0);

        cout << solve(0, done, vc, n);
    }
    
    return 0;
}