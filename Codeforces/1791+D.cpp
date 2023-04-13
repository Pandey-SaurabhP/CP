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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector <vector <bool>> preEx(n, vector <bool> (26, 0));
        vector <int> preCnt(n, 0);

        preEx[0][s[0] - 'a'] = 1;
        preCnt[0] = 1;


        for(int i = 1; i < n; ++i){
            preEx[i] = preEx[i - 1];
            preEx[i][s[i] - 'a'] = 1;

            int cnt = 0;
            for(int j = 0; j < 26; ++j){
                if(preEx[i][j]){
                    ++cnt;
                }
            }

            preCnt[i] = cnt;
        }

        vector <vector <bool>> postEx(n, vector <bool> (26, 0));
        vector <int> postCnt(n, 0);

        postEx[n - 1][s[n - 1] - 'a'] = 1;
        postCnt[n - 1] = 1;

        for(int i = n - 2; i >= 0; --i){
            postEx[i] = postEx[i + 1];
            postEx[i][s[i] - 'a'] = 1;

            int cnt = 0;
            for(int j = 0; j < 26; ++j){
                if(postEx[i][j]){
                    ++cnt;
                }
            }

            postCnt[i] = cnt;
        }

        int ans = 2;

        for(int i = 0; i < n - 1; ++i){
            ans = max(ans, preCnt[i] + postCnt[i + 1]);
        }

        cout << ans << "\n";
    }
    
    return 0;
}