// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 2e5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <int>> adj(mxn);
int par[mxn];
int imp[mxn];
vector <int> pr(mxn);

int dfs(int root, int par){
    
    int sm;

    for(auto it : adj[root]){
        if(it != par){
            
        }
    }
}

int main(){

    // fast();

    int n, q;
    cin >> n >> q;

    read(pr, mxn);

    for(int i = 0; i <= n; ++i){
        par[i] = i;
    }

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        par[v] = u;
    }

    while(q){
        int type;
        cin >> type;

        if(type == 1){
            int x;
            cin >> x;

            cout << imp[x] << "\n";
        }
        else{
            int x;
            cin >> x;

            int p = par[x];
            int sp = par[p];

            adj[x].push_back(p);
            removeX(p, x);

            if(p != sp){
                adj[sp].push_back(x);
            }

        }
    }

    
    return 0;
}