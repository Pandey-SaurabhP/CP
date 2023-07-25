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
        string s;
        cin >> s;

        int n = s.size();

        int i = 0;
        while(s[i] == '0' || s[i] == '?'){
            s[i] = '0';
            ++i;
        }

        i = n - 1;
        while(s[i] == '1' || s[i] == '?'){
            s[i] = '1';
            --i;
        }

        for(int i = 0; i < n; ++i){
            if(s[i] == '?'){
                if(i - 1 >= 0 && s[i - 1] == '0'){
                    s[i] = '0';
                }
                else if(i + 1 < n && s[i + 1] == '0'){
                    s[i] = '0';
                }
                else{
                    s[i] = '1';
                }
            }
        }

        cout << s << "\n";

    }
    
    return 0;
}