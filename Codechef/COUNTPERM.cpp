// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    // fast();
    vector <int> factorial(mxn);
    factorial[0] = 1;
    for(int i = 1; i < mxn; ++i){
        factorial[i] = factorial[i - 1] * i;
    }

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector <int> b(m);
        read(b, m);

        vector <int> cnt(m);

        for(int i = 0; i < m; ++i){
            cnt[i] = b[i] - i - 1;
        }

        vector <vector <int>> dp(m + 1, vector <int> (n - m + 5, 0));
        dp[0][0] = 1;

        for(int j = 0; j <= cnt[0]; ++j){
            dp[1][j] = 1;
        }

        cout << "<CNT>  : ";
        print(cnt, m);

        vector <int> pre(n - m + 1, 0);
        vector <int> mult(n - m + 1, 0);

        for(int i = 0; i <= n - m; ++i){
            mult[i] = factorial[n - m - i];
        }

        cout << "<MULT> : ";
        print(mult, n - m + 1);


        for(int i = 2; i <= m; ++i){

            // Build prefix sum
            pre[0] = mult[0];

            for(int j = 1; j <= n - m; ++j){
                pre[j] = (dp[i - 1][j] * mult[j]) + pre[j - 1];
            }

            for(int j = 0; j <= n - m; ++j){
                dp[i][j] += pre[j];

                if(j - cnt[i - 1] > 0){
                    dp[i][j] -= pre[j - cnt[i - 1] - 1];
                }

                // dp[i][j] /= factorial[j];
            }
        }

        for(int j = 0; j <= m; ++j){
            print(dp[j], n - m + 1);
        }
        
    }
    
    return 0;
}