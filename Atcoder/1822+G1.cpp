// pandeyGRocks
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

vector <vector <ll>> fct(mxn);

int main(){

    fast();

    for(ll i = 2; i < mxn; ++i){
        for(ll j = 2 * i; j < mxn; j += i){
            fct[j].push_back(i);
        }
    }

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        unordered_map <ll, ll> mp;

        for(auto it : a){
            if(!mp.count(it)){
                mp[it] = 0;
            }

            ++mp[it];
        }

        ll ans = 0;

        for(auto z : mp){
            ll x = z.first;

            if(z.second >= 3){
                ll cnt = z.second;
                ans += (cnt * (cnt - 1) * (cnt - 2));
            }

            for(auto it : fct[z.first]){
                ll xc = 0;
                ll tmp = z.first;

                while(tmp % it == 0){
                    ++xc;
                    tmp /= it;
                }

                ll localAns = z.second;

                if(xc >= 2){
                    if(mp.count(z.first / it)){
                        localAns *= mp[z.first / it];
                    }
                    else{
                        localAns = 0;
                    }

                    if(localAns != 0){
                        if(mp.count(z.first / (it * it))){
                            localAns *= mp[z.first / (it * it)];
                        }
                        else{
                            localAns = 0;
                        }
                    }

                    ans += localAns;
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}