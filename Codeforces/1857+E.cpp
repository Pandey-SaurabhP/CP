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
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        vector <ll> b = a;

        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        sort(a.begin(), a.end());
        
        ll ans = n;

        for(ll i = 1; i < n; ++i){
            ans += (a[i] - a[i - 1]) * (n - i);
        }

        map <ll, ll> mp;
        mp[a[0]] = ans;
        // cout << ans << " ";


        for(ll i = 1; i < n; ++i){
            ans -= (a[i] - a[i - 1]) * (n - i);
            ans += (a[i] - a[i - 1]) * i;

            mp[a[i]] = ans;
            // cout << ans << " ";
        }

        for(auto it : b){
            cout << mp[it] << " ";
        }
        cout << "\n";

        // cout << "\n";
    }
    
    return 0;
}