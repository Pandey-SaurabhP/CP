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

        vector <int> a(n);
        read(a, n);

        int mn = 1;
        int mx = n;

        int l = 0;
        int r = n - 1;

        bool fnd = 0;

        while(l < r){

            if(a[l] != mn && a[l] != mx && a[r] != mn && a[r] != mx){
                cout << l + 1 << " " << r + 1 << "\n";
                fnd = 1;
                break;
            }

            if(a[l] == mn){
                ++l;
                ++mn;
            }
            if(a[l] == mx){
                ++l;
                --mx;
            }

            if(a[r] == mn){
                --r;
                ++mn;
            }
            if(a[r] == mx){
                --r;
                --mx;
            }
        }

        if(!fnd){
            cout << "-1\n";
        }
    }
    
    return 0;
}