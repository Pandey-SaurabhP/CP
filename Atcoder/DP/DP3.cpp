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

int memo[100005][4];

int solve(int i, int last, vector <vector <int>> &a, int n){

    if(i == n){
        return 0;
    }

    // cout << i << " " << last << "\n";

    if(memo[i][last] != -1){
        return memo[i][last];
    }

    int ans = INT_MIN;

    if(last != 1){
        ans = max(ans, a[i][0] + solve(i + 1, 1, a, n));
    }

    if(last != 2){
        ans = max(ans, a[i][1] + solve(i + 1, 2, a, n));
    }

    if(last != 3){
        ans = max(ans, a[i][2] + solve(i + 1, 3, a, n));
    }   

    return memo[i][last] = ans;
}

int main(){

    // fast();
    for(int i = 0; i < 100005; ++i){
        for(int j = 0; j < 4; ++j){
            memo[i][j] = -1;
        }
    }

    int n;
    cin >> n;

    vector <vector <int>> a(n, vector <int> (3));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> a[i][j];
        }
    } 

    cout << solve(0, 0, a, n);

    
    return 0;
}