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

        vector <int> sm;

        for(int i = 1; i < n; ++i){
            sm.push_back(abs(a[i] - a[i - 1]));
        }

        sort(sm.begin(), sm.end());
        reverse(sm.begin(), sm.end());


        int ans = 0;
        for(int i = k - 1; i < sm.size(); ++i){
            ans += sm[i];
        }

        cout << ans << "\n";
    }
    
    return 0;
}