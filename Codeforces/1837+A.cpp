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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int x, k;
        cin >> x >> k;

        vector <int> ans;

        for(int i = x; i >= 0; --i){
            if(i % k != 0){
                while(x >= i){
                    ans.push_back(i);
                    x -= i;
                }
            }

            if(x == 0){
                break;
            }
        }

        cout << ans.size() << "\n";
        print(ans, ans.size());
    }
    
    return 0;
}