#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << '\t'; }

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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector <int> a(n);
        read(a, n);

        vector <int> b(a[n - 1]);
        for(int i = 0; i < a[n - 1]; ++i){
            b[i] = i + 1;
        }

        for(int i = 0; i < n; ++i) --a[i];

        

        int x = a[n - 1] + 1;
        print(b, b.size());

        int mx = a[n - 1] + 1;

        for(int i = 0; i < 20; ++i){
            
            vector <int> tmp;

            for(int j = 0; j < n; ++j){
                b[a[j]] = -1;
            }

            for(int j = 0; j < b.size(); ++j){
                if(b[j] != -1){
                    tmp.push_back(b[j]);
                }
            }

            while(tmp.size() != x){
                tmp.push_back(mx + 1);
                ++mx;
            }

            b = tmp;

            print(b, x);
        }


    }
    
    return 0;
}