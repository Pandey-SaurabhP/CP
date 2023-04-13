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
        int n, m;
        cin >> n >> m;

        cout << "? " << 1 << " " << 1 << endl;

        int d1;
        cin >> d1;

        if(d1 + 1 > m){
            // then given d1 is y dist, has to be y dist
            int r = d1 + 1;

            cout << "? " << d1 + 1 << " " << 1 << endl;
            int d2;
            cin >> d2;

            int c = d2 + 1;

            cout << "! " << r << " " << c << endl;
        }
        else{
            // Given distance could be x or y dist
            cout << "? " << 1 << " " << d1 + 1 << endl;
            int d2;
            cin >> d2;

            int r, c;
            r = c = -1;

            if(d2 < d1){
                // d1 is x dist
                c = d1 + 1;

                // and d2 is y dist
                r = d2 + 1;

                cout << "! " << r << " " << c << endl;
            }
            else{
                // d1 is y dist;
                r = d1 + 1;

                cout << "? " << r << " " << 1 << endl;
                int d3;
                cin >> d3;

                c = d3 + 1;

                cout << "! " << r << " " << c << endl;
            }


        }
    }
    
    return 0;
}