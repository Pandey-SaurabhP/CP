// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 2e5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <pair <ll, ll>>> adjList(mxn);
map <ll, ll> mp;

void dfs(ll root, ll par, ll val){

    mp[root] = val;

    for(auto it : adjList[root]){
        if(it.first != par){
            dfs(it.first, root, val ^ it.second);
        }
    }

}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        for(ll i = 0; i <= n; ++i){
            adjList[i].clear();
        }

        mp.clear();

        for(ll i = 0; i < n - 1; ++i){
            ll u, v, w;
            cin >> u >> v >> w;

            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }

        dfs(1, 1, 0);

        vector <pair <ll, ll>> pr;
        vector <ll> xors;

        for(auto it : mp){
            pr.push_back({it.second, it.first});
            xors.push_back(it.second);
        }

        sort(pr.begin(), pr.end());
        sort(xors.begin(), xors.end());

        vector <vector <pair <ll, ll>>> cnt((1 << 21) + 1);

        bool ok = 0;

        for(ll i = 0; i < xors.size(); ++i){
            for(ll j = i + 1; j < xors.size(); ++j){


                ll xx = xors[i] ^ xors[j];

                cnt[xx].push_back({pr[i].second, pr[j].second});

                if(cnt[xx].size() > 1){

                    int aa, bb, cc, dd;
                    aa = cnt[xx][0].first;
                    bb = cnt[xx][0].second;

                    cc = cnt[xx][1].first;
                    dd = cnt[xx][1].second;

                    if(aa > bb){
                        swap(aa, bb);
                    }
                    if(cc > dd){
                        swap(cc, dd);
                    }

                    cout << aa << " " << bb << " " << cc << " " << dd << "\n";
                    // cout << cnt[xx][0].first << " " << cnt[xx][0].second << " " << cnt[xx][1].first << " " << cnt[xx][1].second << "\n";
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        if(!ok){
            cout << "-1\n";
        }

    }
    
    return 0;
}