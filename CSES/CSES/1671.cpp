#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 5;
typedef long long ll;

vector <vector <pair <ll, ll>>> adj(mxn);
vector <ll> dist(mxn, 1000000000000000ll);

void dijkstra(){
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> pq;

    pq.push({0, 1});

    dist[1] = 0;

    while(!pq.empty()){

        ll edge = pq.top().second;
        ll wt = pq.top().first;

        pq.pop();

        if(wt > dist[edge]) continue;

        for(auto it : adj[edge]){
            if(dist[it.second] > wt + it.first){
                dist[it.second] = wt + it.first;
                pq.push({it.first + wt, it.second});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
    }

    dijkstra();

    for(ll i = 1; i <= n; ++i){
        cout << dist[i] << " ";
    }
    cout << "\n";


    return 0;
}
