#include <bits/stdc++.h>

using namespace std;

const int mxn = 2505;
vector <vector <pair <int, int>>> adj(mxn);

int main(){

    int n, m;
    cin >> n >> m;

    vector <pair <pair <int, int>, int>> edges;

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        w *= -1;

        adj[u].push_back({v, w});
        edges.push_back({{u, v}, w});
    }

    vector <int> dist(n + 1, 100000);
    dist[1] = 0;


    for(int j = 0; j < n; ++j){
        for(int i = 0; i < m; ++i){
            int u = edges[i].first.first;
            int v = edges[i].first.second;
            int w = edges[i].second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i <= n; ++i){
        cout << dist[i] << " ";
    }

    return 0;
}
