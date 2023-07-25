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

int dp[200005][2][5];

int solve(int i, int changes, int mx, vector <int> &a, int &n){

    if(i == n){
        return 0;
    }

    if(dp[i][changes][mx] != INT_MIN){
        return dp[i][changes][mx];
    }
 
    int ans = solve(i + 1, changes, max(mx, a[i]), a, n);
    ans += (a[i] >= mx? pow(10, a[i]): -pow(10, a[i]));

    if(!changes){

        for(int j = 0; j <= 4; ++j){

            int a1 = solve(i + 1, changes + 1, max(mx, j), a, n);
            a1 += (j >= mx? pow(10, j): -pow(10, j));

            ans = max(ans, a1);
        }
    }

    return dp[i][changes][mx] = ans;
}

int main(){

    // fast();

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        int n = s.size();

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 5; ++k){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }

        vector <int> a(n);
        for(int i = 0; i < n; ++i){
            a[i] = s[i] - 'A';
        }

        reverse(a.begin(), a.end());

        // print(a, n);
        cout << solve(0, 0, 0, a, n) << '\n';
    }
    
    return 0;
}