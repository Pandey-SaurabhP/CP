// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

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
        ll n, m, k;
        cin >> n >> m >> k;

        vector <pair <ll, ll>> obs;

        for(ll i = 0; i < k; ++i){
            ll x, y;
            cin >> x >> y;

            if(x == n || y == m){
                continue;
            }
            else{
                obs.push_back({x, y});
            }
        }

        k = obs.size();
        sort(obs.begin(), obs.end());

        if(k == 0){
            cout << n + m - 2 << "\n";
            continue;
        }

        map <pair <ll, ll>, ll> mp;
        mp.insert({obs[0], 1}); 

        ll mx = 1;

        for(ll i = 1; i < k; ++i){
            ll tp = 1;

            vector <pair <ll, ll>> vc;

            for(auto it : mp){
                if((it.first.first < obs[i].first) && (it.first.first < obs[i].second)){
                    tp = max(tp, mp[obs[i]] + 1);
                    vc.push_back(it.first);
                }
            }

            for(auto it : vc){
                mp.erase(it);
            }
            
            mp[obs[i]] = tp;

            mx = max(mx, tp);
        }

        ll ans = n + m - 2;
        ans -= mx;

        cout << ans << "\n";



    }
    
    return 0;
}