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
        int n, m;
        cin >> n >> m;

        vector <vector <int>> a(n, vector <int> (m));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> a[i][j];
            }
        }

        vector <vector <int>> mx(n, vector <int> (m));

        for(int i = 0; i < m; ++i){
            mx[0][i] = a[0][i];
        }

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(j - 1 >= 0 && j + 1 < m){
                    mx[i][j] = max(max(mx[i - 1][j - 1], mx[i - 1][j]), max(mx[i - 1][j + 1], a[i][j]));
                }
                else if(j - 1 >= 0){
                    mx[i][j] = max(mx[i - 1][j - 1], max(mx[i - 1][j], a[i][j]));
                }
                else if(j + 1 < m){
                    mx[i][j] = max(mx[i - 1][j], max(mx[i - 1][j + 1], a[i][j]));
                }
                else{
                    mx[i][j] = max(mx[i - 1][j], a[i][j]);
                }
            }
        }

        // for(int i = 0; i < n; ++i){
        //     for(int j = 0; j < m; ++j){
        //         cout << mx[i][j] << " "; 
        //     }
        //     cout << "\n";
        // }

        vector <vector <bool>> ans(n, vector <bool> (m, 0));

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mx[i][j] > a[i][j]){
                    ans[i][j] = 0;
                }
                else{
                    ans[i][j] = 1;
                }
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << ans[i][j];
            }
            cout << "\n";
        }

    }
    
    return 0;
}