#include <bits/stdc++.h>

using namespace std;


const int mxn = 1e5 + 5;
vector <vector <pair <int, int>>> adj(mxn);

int main(){

    int n, m, k;
    cin >> n >> m >> k;


    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    priority_queue <pair <int, int>> pq;

    pq.push({1, 0});
    pq.push({-1, -1});

    vector <int> ans;

    while(!pq.empty()){

        pair <int, int> tp = pq.top();


    }



    return 0;
}
