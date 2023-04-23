// pandeyGRocks
#include <bits/stdc++.h>
#include <typeinfo>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 2e5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <int>> adj(mxn);
vector <int> vis(mxn, 0);
vector <int> dp (mxn, -1);


int dfs(int root){
    
    if(dp[root] != -1){
        return dp[root];
    }

    int mx = 1;

    for(auto it : adj[root]){
        mx = max(1 + dfs(it), mx);
    }

    return dp[root] = max(mx, dp[root]);
}

int main(){

    // fast();

    int n, m;
    cin >> n >> m;

    // vector <int> a = {5,4,3,1,2};

    // sort(a.begin(), a.end(), [](int i, int j){
    //     return i < j;
    // });

    // print(a, 5);

    // cout << typeid(adj.size()).name() << "\n";

    for(int i = 0; i < m; ++i){
        int from, to;

        cin >> from >> to;
        adj[from].push_back(to);
    }

    for(int i = 1; i <= n; ++i){
        if(!vis[i]){
            dfs(i);
        }
    }

    int mx = 0;

    for(int i = 0; i <= n; ++i){
        mx = max(mx, dp[i] - 1);
    }

    cout << mx;
    


    
    return 0;
}