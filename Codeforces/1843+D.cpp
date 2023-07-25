#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 2e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <ll>> adj(mxn);
vector <ll> ass(mxn);

void dfs(ll root, ll par){

    if(adj[root].size() == 1 && adj[root][0] == par){
        ass[root] = 1;
        return;
    }

    for(auto it : adj[root]){
        if(it != par){
            dfs(it, root);
        }
    }


    ll cnt = 0;

    for(auto it : adj[root]){
        if(it != par){

            cnt += ass[it];

        }
    }

    ass[root] = cnt;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        for(ll i = 0; i <= n + 5; ++i){
            adj[i].clear();
            ass[i] = 1;
        }

        for(ll i = 0; i < n - 1; ++i){
            ll x, y;
            cin >> x >> y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1, 1);
        // cout << "\n";

        // for(ll i = 1; i <= n; ++i){
        //     cout << i << " : " << ass[i] << "\n";
        // }

        ll q;
        cin >> q;

        while(q--){
            ll x, y;
            cin >> x >> y;

            cout << ass[x] * ass[y] << "\n";

        }
    }
    
    return 0;
}