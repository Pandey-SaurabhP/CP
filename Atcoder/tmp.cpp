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

    // fast();

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        s = "*" + s;
        s = s + "*";

        int n = s.size();

        vector <bool> pr(256, 0);

        for(int i = 0; i < n; ++i){
            pr[s[i]] = 1;
        }

        vector <bool> ok(256, 0);

        for(int i = 1; i <= n; ++i){
            if(s[i - 1] != s[i] && s[i + 1] != s[i]){
                ok[s[i]] = 1;
            }
        }

        for(char i = 'a'; i <= 'z'; ++i){
            if(pr[i] && ok[i]){
                cout << i;
            }
        }

        cout << "\n";
    }
    
    return 0;
}