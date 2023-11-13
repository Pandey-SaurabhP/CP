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

ll dp[101][100001];

int main(){

    // fast();
    memset(dp, -1, sizeof(dp));

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    read(a, n);

    if(a[0] == 0){
        ll ans = 0;

        for(ll i = 1; i <= m; ++i){
            ans += solve(i, 1, a, n, m);
        }
        cout << ans % mod;
    }
    else{

        for(ll i = 1; i < n; ++i){
            ll last = a[i - 1];
            for(ll j = )
        }
    }


    return 0;
}

