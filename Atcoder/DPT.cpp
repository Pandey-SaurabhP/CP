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

int dp[3005][3005];

int main(){

    // fast();

    int n;
    cin >> n;

    --n;

    string s;
    cin >> s;

    for(int i = 1; i <= n + 1; ++i){
        dp[0][i] = 1; // Set first element as i
    }

    for(int i = 1; i <= n; ++i){

        
        for(int j = 1; j <= n + 1; ++j){

            for(int k = 1; k <= n + 1; ++k){

                if(s[i - 1] == '<' && k < j){
                    dp[i][j] += dp[i - 1][k];
                }
                else if(s[i - 1] == '>' && k >= j){
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n + 1; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    int sm = 0;
    for(int i = 0; i <= n + 1; ++i){
        sm += dp[n][i];
    }

    cout << sm << "\n";
    
    return 0;
}