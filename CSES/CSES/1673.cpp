// Bellman Ford

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll inf = 1e13 + 5;

vector <vector <int>> adj(2505);

bool dfs(int root, int n, vector <bool> &vis){
    if(root == n){
        return 1;
    }

    vis[root] = 1;

    bool ans = 0;

    for(auto it : adj[root]){
        if(!vis[it]){
            ans |= dfs(it, n, vis);
        }
    }

    return ans;
}

int main(){
    ll n, m;
    cin >> n >> m;

    vector <pair <pair <ll, ll>, ll>> edge;

    for(ll i = 0; i < m; ++i){
        ll u, v, w;
        cin >> u >> v >> w;

        edge.push_back({{u, v}, -w});
        adj[u].push_back(v);
    }

    vector <ll> dist(n + 1, inf);
    dist[1] = 0;

    for(ll i = 0; i < n; ++i){
        for(auto it : edge){
            pair <pair <ll, ll>, ll> pr = it;

            ll u = pr.first.first;
            ll v = pr.first.second;
            ll w = pr.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }


    vector <ll> old = dist;

    for(ll i = 0; i < n; ++i){
        for(auto it : edge){
            pair <pair <ll, ll>, ll> pr = it;

            ll u = pr.first.first;
            ll v = pr.first.second;
            ll w = pr.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    bool reachable = 0;
    vector <bool> vis(n + 1, 0);
    vector <bool> vis2(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        if(dist[i] != old[i]){
            if(dfs(i, n, vis) && dfs(1, i, vis2)){
                reachable = 1;
                break;
            }

        }
    }





    if(reachable){
        cout << -1 << "\n";
    }
    else{
        cout << -dist[n];
    }
    return 0;
}
