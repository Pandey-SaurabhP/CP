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
        string a, b;
        cin >> a >> b;

        int n = b.size();

        reverse(a.begin(), a.end());
        while(a.size() != n){
            a += '0';
        }
        reverse(a.begin(), a.end());

        string alpha, beta;
        alpha = a;
        beta = b;

        int ans = 0;

        for(int i = n - 1; i >= 0; --i){

            int mx = 0;
            char sa = a[i];
            char sb = b[i];

            for(int j = '9'; j >= '0'; --j){
                for(int k = '0'; k <= '9'; ++k){

                    a[i] = j;
                    b[i] = k;


                    if(a < alpha || a > beta) continue;
                    if(b < alpha || b > beta) continue;

                    if(mx < abs(a[i] - b[i])){
                        mx = a[i] - b[i];
                        sa = a[i];
                        sb = b[i];
                    }


                }
            }

            a[i] = sa;
            b[i] = sb;
        }

        // cout << a << " " << b << "\n";
        for(int i = 0; i < n; ++i){
            ans += abs(a[i] - b[i]);
        }

        cout << ans << "\n";
    }
    
    return 0;
}