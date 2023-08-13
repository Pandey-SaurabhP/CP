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

bool isValid(vector <ll> a, ll pos, ll val, ll k){
    ll n = a.size();

    ll cnt = 0;
    bool ok = 0;

    for(ll i = pos; i < n; ++i){
        if(a[i] >= val){
            ok = 1;
            break;
        }

        cnt += val - a[i];
        
        --val;
    }
    if(!ok) return 0;
    if(cnt <= k) return 1;
    return 0;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        vector <ll> a(n);
        read(a, n);

        ll mx = a[0];

        vector <ll> b;

        for(ll i = 0; i < n; ++i){
            // Make the ith element largest

            ll lo = a[i];
            ll hi = INT_MAX;

            while(lo < hi){
                ll mid = (lo + hi) / 2;

                if(isValid(a, i, mid, k)){
                    mx = max(mx, mid);
                    lo = mid + 1;
                }
                else{
                    hi = mid;
                }
            }
        }

        cout << mx << "\n";
    }
    
    return 0;
}