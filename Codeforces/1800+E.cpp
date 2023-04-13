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
        int n, k;
        cin >> n >> k;

        string s1, s2;
        cin >> s1 >> s2;

        bool ok = 1;

        vector <int> cnt(256, 0);

        for(int i = 0; i < n; ++i){
            cnt[s1[i]]++;
            cnt[s2[i]]--;
        }

        for(int i = 0; i < 256; ++i){
            if(cnt[i] != 0){
                ok = 0;
            }
        }

        if(!ok){
            cout << "NO\n";
            continue;   
        }


        if(n <= k){
            if(s1 == s2){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else if(n >= k && n < 2 * k){
            int st = n - k;
            int ed = k;

            bool ok = 1;

            for(int i = st; i < ed; ++i){
                if(s1[i] != s2[i]){
                    ok = 0;
                    break;
                }
            }

            if(ok){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "YES\n";
        }


    }
    
    return 0;
}