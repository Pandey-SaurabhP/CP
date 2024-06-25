#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 5;

vector <int> color(mxn, -1);
vector <vector <int>> adj(mxn);

bool ok = 1;

void dfs(int root, int c){
    if(!ok) return;

    color[root] = c;

    for(auto it : adj[root]){
        if(color[it] == -1){
            dfs(it, (c == 1? 2: 1));
        }
        else{
            if(c == color[it]){
                ok = 0;
                return;
            }
        }
    }

}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; ++i){
        if(color[i] == -1){
            dfs(i, 1);
        }
    }

    if(!ok){
        cout << "IMPOSSIBLE";
    }
    else{
        for(int i = 1; i <= n; ++i){
            cout << color[i] << " ";
        }
    }

    return 0;
}
