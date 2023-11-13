#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> adj(2505);
vector <int> ans;
vector <bool> vis(2505, 0);

bool dfs(int root){

    ans.push_back(root);
    if(vis[root]){
        return 1;
    }


    vis[root] = 1;
    for(auto it : adj[root]){
        if(dfs(it)) return 1;;
    }

    ans.pop_back();

    return 0;
}

int main(){

    int n, m;
    cin >> n >> m;

    vector <pair <pair <int, int>, int>> edge;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(v);
        edge.push_back({{u, v}, w});
    }

    vector <int> dist(n, INT_MAX);

    for(int i = 0; i < n; ++i){
        for(auto it : edge){
            pair <pair<int, int>, int> tmp = it;
            int u = tmp.first.first;
            int v = tmp.first.second;
            int w = tmp.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    vector <int> old = dist;

    for(int i = 0; i < n; ++i){
        for(auto it : edge){
            pair <pair<int, int>, int> tmp = it;
            int u = tmp.first.first;
            int v = tmp.first.second;
            int w = tmp.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    int cycleID = -1;

    for(int i = 1; i <= n; ++i){
        if(dist[i] != old[i]){
            cycleID = i;
            break;
        }
    }

    if(!dfs(cycleID)){
        cout << "NO";
    }
    else{
        vector <int> aa;
        int lst = ans[ans.size() - 1];
        aa.push_back(lst);

        for(int i = ans.size() - 2; i >= 0; --i){
            aa.push_back(ans[i]);
            if(ans[i] == lst) break;
        }

        reverse(aa.begin(), aa.end());

        cout << "YES\n";
        for(int i = 0; i < aa.size(); ++i){
            cout << aa[i] << " ";
        }
        cout << "\n";
    }


    return 0;
}
