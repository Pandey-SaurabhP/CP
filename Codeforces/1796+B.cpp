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
        string a, b;
        cin >> a >> b;

        if(a[a.size() - 1] == b[b.size() - 1]){
            cout << "YES\n*" << a[a.size() - 1] << "\n";
        }
        else if(a[0] == b[0]){
            cout << "YES\n" << a[0] << "*\n";
        }
        else{
            string ans = ".";

            for(int i = 0; i < a.size() - 1; ++i){
                for(int j = 0; j < b.size() - 1; ++j){
                    if(a[i] == b[j] && a[i + 1] == b[j + 1]){
                        ans = '*';
                        ans += a[i];
                        ans += a[i + 1];
                        ans += '*';

                        break;
                    }
                }

                if(ans != ".") break;
            }

            if(ans == "."){
                cout << "NO\n";
            }
            else{
                cout << "YES\n" << ans << "\n";
            }
        }
    }
    
    return 0;
}