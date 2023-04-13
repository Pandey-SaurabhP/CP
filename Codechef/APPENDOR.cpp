// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << endl; } else { cout << a[i] << ' '; }

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

    int t;
    cin >> t;

    while(t--){
        int n, y;
        cin >> n >> y;

        vector <int> a(n);
        read(a, n);

        int v = 0;

        for(int i = 0; i < n; ++i){
            v |= a[i];
        }   

        bool pos = 1;
        int ans = 0;

        if(v > y){
            pos = 0;
        }

        int p = 0;

        while(y){
            int ldy = y % 2;
            int ldv = v % 2;

            if(ldy == 0 && ldv != 0){
                pos = 0;
                break;
            }
            
            if(ldy != 0 && ldv == 0){
                ans |= (1 << p);
            }

            y /= 2;
            v /= 2;
            ++p;
        }

        if(!pos){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
    
    return 0;
}