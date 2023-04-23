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

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector <vector <int>> dp(n + 1, vector <int> (m + 1));

    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= m; ++j){

            if(i == 0 || j == 0){
                dp[i][j] = 0;                
            }
            else{
                dp[i][j] = max(dp[i - 1][j - 1] + (s[i - 1] == t[j - 1]), 
                            max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // for(int i = 0; i <= n; ++i){
    //     for(int j = 0; j <= m; ++j){
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    string ans;

    int j = m;
    int i = n;

    while(i > 0 && j > 0){
        if(j - 1 >= 0 && dp[i][j - 1] == dp[i][j]){
            --j;
            continue;
        }

        if(i - 1 >= 0 && dp[i - 1][j] == dp[i][j]){
            --i;
            continue;
        }
        
        if(i - 1 >= 0 && j - 1 >= 0 && dp[i - 1][j - 1] != dp[i][j]){
            ans += t[j - 1];
            --i;
            --j;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans;
    
    return 0;
}