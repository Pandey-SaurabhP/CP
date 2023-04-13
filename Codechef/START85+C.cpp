// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isValid(ll r, ll c, ll ans, ll k, vector <vector <ll>> &pre, ll n, ll m){

    ll mxr = min(n, r + ans);
    ll mxc = min(m, c + ans);

    ll mnr = max(1ll, r - ans);
    ll mnc = max(1ll, c - ans);

    // if(ans <= 5){
    //     cout << ans << " : " << mnr << " " << mnc << " " << mxr << " " << mxc << "  ";
    // }

    if(pre[mxr][mxc] - pre[mnr - 1][mxc] - pre[mxr][mnc - 1] + pre[mnr - 1][mnc - 1] >= k){
        // if(ans <= 5) cout << "Valid!\n";
        return 1;
    }

    // if(ans <= 5) cout << "Not valid!\n";

    return 0;
}


int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        cin >> n >> m;

        ll k;
        cin >> k;

        vector <vector <ll>> a(n, vector <ll> (m));
        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < m; ++j){
                cin >> a[i][j];
            }
        }

        vector <vector <ll>> pre(n + 1, vector <ll> (m + 1));
        for(ll i = 0; i <= n; ++i){
            for(ll j = 0; j <= m; ++j){
                if(i == 0 || j == 0){
                    pre[i][j] = 0;
                }
                else{
                    pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
                    pre[i][j] += a[i - 1][j - 1];
                }
            }
        }

        // for(ll i = 0; i <= n; ++i){
        //     for(ll j = 0; j <= m; ++j){
        //         cout << pre[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        ll ans = -1;

        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < m; ++j){

                // Keep mentor at current

                if(a[i][j] == 0){
                    continue;
                }
                else{

                    ll l = 0;
                    ll r = 1e9;

                    ll localAns = -1;

                    while(l < r){
                        ll mid = (l + r) / 2;

                        if(isValid(i + 1, j + 1, mid, k + 1, pre, n, m)){
                            localAns = mid;
                            r = mid;
                        }
                        else{
                            l = mid + 1;
                        }
                    }

                    if(localAns != -1){

                        if(ans == -1){
                            ans = localAns;
                        }
                        else ans = min(ans, localAns);
                    }

                    // cout << i << " " << j << " : "  << localAns << "\n";
                }

                
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}