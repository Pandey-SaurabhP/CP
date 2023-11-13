
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

ll getPower(ll b, ll e){
    ll ans = 1;

    while(e){
        ans *= b;
        --e;
    }

    return ans;
}

ll hashFunc(string &s){
    ll po = 0;
    ll res = 0;

    for(ll i = 0; i < s.size(); ++i){
        res += (s[i] - 'a') * getPower(26ll, po);
        ++po;
    }

    return res;
}


int main(){
    fast();
    ll n, m;
    cin >> n >> m;

    vector <string> a(n);
    read(a, n);

    map <ll, ll> hs;

    for(ll i = 0; i < n; ++i){

        ll starAt = 0;

        for(ll j = 0; j < m; ++j){
            if(a[i][j] == '*'){
                starAt = j;
                break;
            }
        }

        for(ll k = 'a'; k <= 'z'; ++k){
            a[i][starAt] = k;
            hs[hashFunc(a[i])] += 1;
        }

        a[i][starAt] = '*';
    }

    ll mn = 1;
    string ans = a[0];

    for(ll i = 0; i < n; i++){
        ll starAt = 0;

        for(ll j = 0; j < m; ++j){
            if(a[i][j] == '*'){
                starAt = j;
                break;
            }
        }

        for(ll k = 'a'; k <= 'z'; ++k){
            a[i][starAt] = k;

            ll cnt = hs[hashFunc(a[i])];

            if(cnt > mn){
                mn = cnt;
                ans = a[i];
            }
            else if(cnt == mn){
                ans = min(ans, a[i]);
            }
        }
    }

    cout << ans << " " << mn;

    return 0;
}









