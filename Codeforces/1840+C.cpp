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
        ll n, k, temp;
        cin >> n >> k >> temp;

        vector <ll> a(n);
        read(a, n);

        vector <ll> id;

        ll ans = 0;

        id.push_back(0);

        for(ll i = 0; i < n; ++i){
            if(a[i] > temp){
                id.push_back(i + 1);
            }
        }

        id.push_back(n + 1);

        // print(id, id.size());

        for(ll i = 1; i < id.size(); ++i){
            if(id[i] - id[i - 1] >= k){
                ll lc = (id[i] - id[i - 1]) - k;
                ans += (lc * (lc + 1)) / 2;
                // cout << id[i - 1] << " " << id[i] << " : " << ans << "\n";
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}