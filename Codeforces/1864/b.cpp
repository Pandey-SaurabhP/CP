
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

    ll t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if(k % 2 == 0){
            sort(s.begin(), s.end());
            cout << s << "\n";
        }
        else{
            string s1, s2;

            for(int i = 0; i < n; ++i){
                if(i % 2 == 0){
                    s1 += s[i];
                }
                else{
                    s2 += s[i];
                }
            }

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            string ans;

            for(int i = 0; i < s1.size(); ++i){
                ans += s1[i];
                if(i < s2.size()){
                    ans += s2[i];
                }
            }

            cout << ans << "\n";
        }
    }

    return 0;
}



