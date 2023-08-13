#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;
ll mxx = 1e9 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <ll> memo(mxn);

ll dfs(ll root, vector <vector <ll>> &adj, set <ll> st, vector <ll> &a){
    if(memo[root] != -1){
        return memo[root];
    }

    if(st.count(root)){
        return memo[root] = 0;
    }

    if(adj[root].size() == 0){
        return memo[root] = a[root];
    }

    ll total = 0;

    for(auto it : adj[root]){
        total += dfs(it, adj, st, a);
    }

    return memo[root] = min(total, a[root]);
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        for(int i = 0; i < n; ++i){
            memo[i] = -1;
        }

        vector <ll> a(n), b(k);
        vector <vector <ll>> adj;
        
        read(a, n);
        read(b, k);

        for(ll i = 0; i < n; ++i){
            ll m;
            cin >> m;

            vector <ll> req(m);
            read(req, m);

            for(ll j = 0; j < m; ++j) req[j]--;

            adj.push_back(req);
        }

        set <ll> st;
        for(auto it : b){
            st.insert(it - 1);
        }

        for(ll i = 0; i < n; ++i){
            if(memo[i] != -1){
                cout << memo[i] << " ";
            }
            else cout << dfs(i, adj, st, a) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}