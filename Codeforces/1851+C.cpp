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
        int n, k;
        cin >> n >> k;

        vector <int> a(n);
        read(a, n);

        int fi = -1;
        int cnt1 = 0;

        for(int i = 0; i < n; ++i){
            if(a[i] == a[0]){
                ++cnt1;

                if(cnt1 == k){
                    fi = i;
                }
            }

            
        }

        int cnt2 = 0;
        int li = -1;

        for(int i = n - 1; i >= 0; --i){
            if(a[i] == a[n - 1]){
                ++cnt2;

                if(cnt2 == k){
                    li = i;
                }
            }

            
        }

        // cout << cnt1 << " " << cnt2 << " " << fi << " " << li << "\n";

        if(fi == -1 || li == -1){
            cout << "NO\n";
        }
        else{
            if(fi < li){
                cout << "YES\n";
                continue;
            }
            if(a[0] == a[n - 1] && cnt1 >= k){
                cout << "YES\n";
                continue;
            }

            cout << "NO\n";
        }
    }
    
    return 0;
}