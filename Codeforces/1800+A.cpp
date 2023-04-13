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

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        string s2;

        s2 += tolower(s[0]);

        for(int i = 1; i < n; ++i){
            if(tolower(s[i]) == tolower(s[i - 1])){
                continue;
            }
            else{
                s2 += tolower(s[i]);
            }
        }

        // cout << s2 << "\n";

        if(s2 == "meow"){
            cout << "YES\n";
        }
        else{
            cout << "NO\n"; 
        }
    }
    
    return 0;
}