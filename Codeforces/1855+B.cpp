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

    vector <ll> a(1);
    a[0] = 1;

    for(ll i = 2; i < 43; ++i){
        ll x = a.size();

        if(a[x - 1] % i == 0){
            a.push_back(a[x - 1]);
        }
        else{
            a.push_back((i / __gcd(i, a[x - 1]) ) * a[x - 1]);
        }
    }

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        int ans = 0;

        for(auto it : a){
            if(n % it == 0){
                ++ans;
            }
        }


        cout << ans << "\n";
    }
    
    return 0;
}