#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll countInversions(vector <ll> &arr, ll n)
{
    vector<ll> v;

    for (ll i = 1; i <= n; i++) {
        v.push_back(i);
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        auto itr = lower_bound(
            v.begin(), v.end(), arr[i]);

        ans += itr - v.begin();

        v.erase(itr);
    }

    return ans;
}

int main(){

//    fast();

    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, n);

    cout << countInversions(a, n);



    return 0;
}

