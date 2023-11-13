#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

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
        int n, m;
        cin >> n >> m;

        string s1, s2;
        cin >> s1 >> s2;

        bool ok2 = 1;

        for(int i = 0; i < n - 1; ++i){
            if(s1[i] == s1[i + 1]){
                ok2 = 0;
                break;
            }
        }

        if(ok2){
            cout << "Yes\n";
            continue;
        }


        // S1 is not okay
        bool ok = 1;

        for(int i = 0; i < m - 1; ++i){
            if(s2[i] == s2[i + 1]){
                ok = 0;
                break;
            }
        }

        if(!ok){
            // Check if already good
            cout << "No\n";
        }
        else{
            char f = s2[0];
            char l = s2[m - 1];

            bool ok3 = 1;

            for(int i = 0; i < n - 1; ++i){
                if(s1[i] == s1[i + 1]){
                    if(f == s1[i] || l == s1[i + 1]){
                        ok3 = 0;
                        break;
                    }
                }
            }

            if(ok3){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }

    return 0;
}




