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

ll fastPower(ll b, ll exp){

    ll ans = 1ll;

    while(exp){

        if(exp % 2ll == 1ll){
            ans = (ans * b);
            ans %= mod;
        }

        exp = exp >> 1ll;
        b *= b;

        b %= mod;
    }

    return ans % mod;
}

ll mmi(ll x){
    return fastPower(x, mod - 2ll) % mod;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, m, k;
        cin >> n >> m >> k;

        ll sm = (((((n * m) % mod) * ((n * m + 1) % mod)) % mod) * mmi(2)) % mod;
        sm %= mod;

        map <ll, ll> rowOps;
        map <ll, ll> colOps;

        while(k--){
            ll type;
            cin >> type;

            if(type == 0){
                ll row, val;
                cin >> row >> val;

                if(!rowOps.count(row)){
                    rowOps[row] = val;
                }
                else{
                    rowOps[row] *= val;
                    rowOps[row] %= mod;
                }

                rowOps[row] %= mod;
            }
            else{
                ll col, val;
                cin >> col >> val;


                if(!colOps.count(col)){
                    colOps[col] = val;
                }
                else{
                    colOps[col] *= val;
                    colOps[col] %= mod;
                }

                colOps[col] %= mod;
            }
        }

        for(auto it : rowOps){

            ll oldSum = ((((m * m) % mod) * (it.first - 1) % mod) % mod) + (((m * (m + 1)) % mod) * mmi(2)) % mod;
            oldSum %= mod;

            sm -= oldSum;

            sm += mod;
            sm %= mod;

            sm += (oldSum * (it.second)) % mod;
            sm %= mod;
        }

        ll firstColSum = n + (((m * ((n * (n - 1)) % mod) % mod) * mmi(2ll)) % mod) % mod;
        firstColSum %= mod;

        ll d = n;

        for(auto it : rowOps){
            firstColSum -= ((m * (it.first - 1 + mod) % mod) + 1ll + mod) % mod;

            firstColSum += mod;
            firstColSum %= mod;
            
            firstColSum += (it.second * ((m * (it.first - 1 + mod) % mod) + 1ll) % mod) % mod;

            firstColSum %= mod;

            d += (it.second - 1);
            d %= mod;
        }

        for(auto it : colOps){

            ll oldSum = (firstColSum) % mod + (((it.first - 1 + mod) % mod * d) % mod);
            oldSum %= mod;

            sm -= oldSum;

            sm += mod;
            sm %= mod;

            sm += (it.second * oldSum);

            sm %= mod;
        }

        cout << sm % mod << "\n";
    }
    
    return 0;
}