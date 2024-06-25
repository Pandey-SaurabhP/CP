#include <bits/stdc++.h>

using namespace std;

long long inf = 1000000000000000ll;

int main(){
    long long n, m, q;
    cin >> n >> m >> q;


    vector <vector <long long>> dist(n + 1, vector <long long> (n + 1, inf));

    for(long long i = 0; i < m; ++i){
        long long u, v, w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for(int i = 0; i <= n; ++i){
        dist[i][i] = 0;
    }


    for(long long k = 1; k <= n; ++k){
        for(long long i = 1; i <= n; ++i){
            for(long long j = 1; j <= n; ++j){
                if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != inf && dist[k][j] != inf){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(long long i = 0; i < q; ++i){
        long long u, v;
        cin >> u >> v;

        cout << (dist[u][v] > inf / 10ll? -1: dist[u][v]) << "\n";
    }
    return 0;
}
