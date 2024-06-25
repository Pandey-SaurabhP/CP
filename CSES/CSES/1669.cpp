#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 5;

vector <vector <int>> adj(mxn);
vector <bool> vis(mxn);

vector <int> ans;

bool dfs(int root, int par){

    vis[root] = 1;
//    for(auto it : ans){
//        cout << it << " ";
//    }
//    cout << "\n";

    for(auto it : adj[root]){
        if(it != par){
            if(vis[it]){
                // found
                ans.push_back(it);
                return 1;
            }
            else{
                ans.push_back(it);
                if(dfs(it, root)){
                    return 1;
                }
                ans.pop_back();
            }
        }
    }

    return 0;
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

    bool ok = 0;
    for(int i = 1; i <= n; ++i){
        if(vis[i]){
            continue;
        }

        ans.push_back(i);
        ok = dfs(i, i);
//        cout << "\n";



        if(ok){
            break;
        }
        else{
            ans.clear();
        }
    }

    if(!ok){
        cout << "IMPOSSIBLE";
    }
    else{
        // Must be a suffix
        int lst = ans[ans.size() - 1];
        vector <int> ax;
        ax.push_back(lst);
        for(int i = ans.size() - 2; i >= 0; --i){
            ax.push_back(ans[i]);

            if(ans[i] == lst) break;
        }

        cout << ax.size() << "\n";
        reverse(ax.begin(), ax.end());
        for(auto it : ax){
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}
