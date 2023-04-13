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

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector <vector <int>> a(n, vector <int> (n));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }

        int cnt = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(a[i][j] != a[n - i - 1][n - j - 1]){
                    a[i][j] ^= 1;
                    ++cnt;
                }
            }
        }

        // cout << cnt << "\n";

        if(cnt == k){
            cout << "YES\n";
        }
        else if(cnt > k){
            cout << "NO\n";
        }
        else{
            if(n % 2 == 1){
                cout << "YES\n";
            }
            else{
                if((k - cnt) % 2 == 0){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    
    return 0;
}