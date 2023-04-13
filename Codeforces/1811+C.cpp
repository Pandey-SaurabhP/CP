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

        vector <int> b(n - 1);
        read(b, n - 1);

        int mx = 0;

        for(auto it : b){
            mx = max(mx, it);
        }

        vector <int> a(n, mx);
        
        for(int i = 0; i < n - 1; ++i){
            if(max(a[i], a[i + 1]) > b[i]){
                if(a[i] > b[i]){
                    a[i] = b[i];
                }
                if(a[i + 1] > b[i]){
                    a[i + 1] = b[i];
                }
            }
        }

        print(a, n);
    }
    
    return 0;
}