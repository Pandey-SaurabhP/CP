// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 3e3 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <float>> dp(mxn, vector <float> (mxn, -1.0));

float solve(int i, int hc, vector <float> &p, int &n){

    if(i == n){
        if(hc > n - hc){
            return 1.00;
        }
        else{
            return 0.00;
        }
    }

    if(dp[i][hc] != -1){
        return dp[i][hc];
    }

    float ans = 0;
    // Consider current to be heads
    ans += p[i] * solve(i + 1, hc + 1, p, n);
    ans += (1.00 - p[i]) * solve(i + 1, hc, p, n);

    return dp[i][hc] = ans; 
}

int main(){

    // fast();

    int n;
    cin >> n;

    vector <float> p(n);
    read(p, n);

    cout << fixed << setprecision(14) << solve(0, 0, p, n);
    
    return 0;
}