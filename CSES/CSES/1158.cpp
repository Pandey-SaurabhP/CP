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

int dp[1001][100001];

int main(){

    // fast();


    int n, x;
    cin >> n >> x;

    vector <int> p(n);
    vector <int> w(n);

    read(p, n);
    read(w, n);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= x; ++j){

            if(i == 0){
                if(j - p[i] >= 0){
                    dp[i][j] = w[i];
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else if(j == 0){
                dp[i][j] = 0;
            }
            else{
                if(j - p[i] >= 0){
                    dp[i][j] = max(dp[i - 1][j - p[i]] + w[i], dp[i][j]);
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }

//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j <= x; ++j){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }

    cout << dp[n - 1][x];

    return 0;
}
