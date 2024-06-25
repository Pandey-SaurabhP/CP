#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[20][2][2][2][256];

string aa;

ll solve(ll i, bool tight1, bool tight2, bool started, ll last, string a, string b, ll n){
    if(i == n){
//        cout << aa << "\n";
        return 1;
    }

    if(dp[i][tight1][tight2][started][last] != -1){
        return dp[i][tight1][tight2][started][last];
    }

    ll ans = 0;

    if(tight1){
        if(tight2){
            for(char j = a[i]; j <= b[i]; ++j){


//                aa += j;
                if(!started){
                    ans += solve(i + 1, !(j > a[i]), !(j < b[i]), j > '0', j, a, b, n);
                }
                else{
                    if(j == last) continue;
                    ans += solve(i + 1, !(j > a[i]), !(j < b[i]), 1, j, a, b, n);
                }
//                aa.pop_back();
            }
        }
        else{
            for(char j = a[i]; j <= '9'; ++j){

//                aa += j;
                if(!started){
                    ans += solve(i + 1, !(j > a[i]), 0, j > '0', j, a, b, n);
                }
                else{
                    if(j == last) continue;
                    ans += solve(i + 1, !(j > a[i]), 0, 1, j, a, b, n);
                }

//                aa.pop_back();
            }
        }
    }
    else{
        if(tight2){
            for(char j = '0'; j <= b[i]; ++j){
                if(j == last) continue;
//                aa += j;
                ans += solve(i + 1, 0, !(j < b[i]), 1, j, a, b, n);

//                aa.pop_back();
            }
        }
        else{
            for(char j = '0'; j <= '9'; ++j){
                if(j == last) continue;
//                aa += j;
                ans += solve(i + 1, 0, 0, 1, j, a, b, n);

//                aa.pop_back();
            }
        }
    }

    return dp[i][tight1][tight2][started][last] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end());

    while(a.size() != b.size()){
        a += "0";
    }

    reverse(a.begin(), a.end());

    cout << solve(0, 1, 1, 0, '-', a, b, b.size());




    return 0;
}
