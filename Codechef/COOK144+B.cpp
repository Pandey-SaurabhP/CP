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

        vector <int> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        int ans = INT_MAX;

        for(int i = 0; i < n; ++i){
            for(int j = i + 2; j < n; ++j){
                
                int key = (a[i] + a[j] + 1) / 2;

                auto id = lower_bound(a.begin() + i + 1, a.begin() + j, key) - a.begin();

                if(id > i && id < j){

                    ans = min(ans, abs(3 * a[id] - (a[i] + a[id] + a[j])));
                }

                if(id - 1 > i && id - 1 < j){
                    ans = min(ans, abs(3 * a[id - 1] - (a[i] + a[id - 1] + a[j])));
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}