
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
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

    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, n);

    vector <ll> ones;

    ones.push_back(-1);

    for(ll i = 0; i < n; ++i){
        if(a[i] == 1){
            ones.push_back(i);
        }
    }

    ones.push_back(n);

        vector <ll> pre;
        pre.push_back(0);
        pre.push_back(ones[1] - ones[0]);
        pre.push_back(ones[2] - ones[1]);

        for(ll i = 3; i < ones.size(); ++i){
            pre.push_back(ones[i] - ones[i - 1] + pre[i - 2]);
        }

//        prll(pre, pre.size());

        ll ans = 0;

        for(ll i = 1; i < ones.size() - 1; ++i){
            ans += pre[i] * (ones[i + 1] - ones[i]);
        }

        cout << ans << "\n";








    return 0;
}





