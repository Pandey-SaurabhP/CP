#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 5;

vector <vector <int>> adj(mxn);

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue <int> q;
    q.push(1);
    q.push(-1);

    vector <bool> vis(mxn, 0);
    vis[1] = 1;

    vector <int> par(mxn);

    par[1] = 1;

    bool fnd = 0;

    int d = 0;


    while(!q.empty()){

        int tp = q.front();
        q.pop();

        if(tp == -1){
            if(q.back() != -1){
                q.push(-1);
            }

            ++d;
            continue;
        }


        for(auto it : adj[tp]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
                par[it] = tp;
            }
        }

        if(tp == n){
                fnd = 1;
            break;
        }
    }

    if(!fnd){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << d + 1 << "\n";

        vector <int> ans;

        int tp = n;

        while(tp != 1){
            ans.push_back(tp);
            tp = par[tp];
        }

        ans.push_back(1);

        reverse(ans.begin(), ans.end());

        for(auto it : ans){
            cout << it << " ";
        }
        cout << "\n";
    }



    return 0;
}
