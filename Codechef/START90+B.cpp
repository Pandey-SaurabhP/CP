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

        vector <int> cnt(256, 0);

        for(char ch : s){
            cnt[ch]++;
        }

        bool allSame = 0;
        for(auto it : cnt){
            if(it == n){
                // All same
                allSame = 1;
                break;
            }
        }

        if(allSame){
            if(n == 1){
                cout << 0 << "\n";
            }
            else if(n == 2){
                cout << 1 << "\n";
            }
            else{
                if(n % 2 == 1){
                    cout << 2 << "\n";
                }
                else{
                    cout << 1 << "\n";
                }
            }

            continue;
        }

        int cc = 0;

        for(auto it : cnt){

            if(it % 2 == 1){
                ++cc;
            }
        }

        if(cc == 0){
            cout << 1 << "\n";
        }
        else if(cc == 1){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    
    return 0;
}