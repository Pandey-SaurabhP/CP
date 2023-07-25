// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
int mxn = 2e5 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <int>> adj(mxn);

void dfs(int root, vector <bool> &vis, int &n){

    vis[root] = 1;

    for(auto it : adj[root]){
        if(!vis[it]){
            dfs(it, vis, n);
        }
    }
}

bool rematch;

void dfs2(int root, int last, vector <bool> &vis, int &n){

    vis[root] = 1;
    cout << "Root " << root + 1 << " " << last + 1 << "\n";

    for(auto it : adj[root]){
        if(it != last && vis[it]){
            cout << "Match : " << root + 1 << " " << it + 1 << " " << last + 1 << "\n";
            rematch = 1;
        }
        if(!vis[it]){
            dfs2(it, root, vis, n);
        }
    }
}

bool fullyConnected(int root, vector <bool> &vis, vector <int> &a, int n){

    int sz = 1;
    int lst = root;

    while(!vis[root]){

        vis[root] = 1;

        if(!vis[a[root]]){
            lst = root;
            root = a[root];
            ++sz;
        }
        else{
            if(lst == a[root]) return 0;
            if(sz >= 3){
                // cout << "Hell!\n";
                return 1;
            }
            return 0;
        }

    }

    return 0;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        for(int i = 0; i <= n; ++i){
            adj[i].clear();
        }

        for(int i = 0; i < n; ++i){
            --a[i];
        }

        for(int i = 0; i < n; ++i){
            adj[i].push_back(a[i]);
            adj[a[i]].push_back(i);
        }

        // max = number of components

        int cmp = 0;
        vector <bool> vis(n + 1, 0);

        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(i, vis, n);
                ++cmp;
            }
        }

        // Now complete cycle components

        int connected = 0;

        for(int i = 0; i < n; ++i) vis[i] = 0;

        for(int i = 0; i < n; ++i){
            if(!vis[i]){

                connected += fullyConnected(i, vis, a, n);
            }
        }

        cout << min(connected + 1, cmp) << " " << cmp << "\n";

    }
    
    return 0;
}