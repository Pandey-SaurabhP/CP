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

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        
        vector <string> s(3);

        cin >> s[0] >> s[1] >> s[2];

        string ans = "DRAW";

        for(int i = 0; i < 3; ++i){
            if((s[i][0] == s[i][1]) && (s[i][1] == s[i][2]) && (s[i][0] != '.')){
                ans = s[i][0];
                break;
            }

            if((s[0][i] == s[1][i]) && (s[1][i] == s[2][i]) && (s[0][i] != '.')){
                ans = s[0][i];
                break;
            }
        }

        if((s[0][0] == s[1][1]) && (s[1][1] == s[2][2]) && (s[1][1] != '.')){
            ans = s[0][0];
        }

        if((s[0][2] == s[1][1]) && (s[1][1] == s[2][0]) && (s[1][1] != '.')){
            ans = s[1][1];
        }

        cout << ans << "\n";
    }
    
    return 0;
}