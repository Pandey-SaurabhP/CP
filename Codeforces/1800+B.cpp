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

        string s;
        cin >> s;

        vector <int> cnt(256, 0);

        for(char ch : s){
            cnt[ch]++;
        }

        int ans = 0;

        for(int i = 'a'; i <= 'z'; ++i){
            ans += min(cnt[i], cnt[i + 'A' - 'a']);

            if(cnt[i + 'A' - 'a'] >= cnt[i]){
                ans += min((cnt[i + 'A' - 'a'] - cnt[i]) / 2, k);
                k -= min(k, (cnt[i + 'A' - 'a'] - cnt[i]) / 2);
            }
            else{
                ans += min((cnt[i] - cnt[i + 'A' - 'a']) / 2, k);
                k -= min(k, (cnt[i] - cnt[i + 'A' - 'a']) / 2);
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}