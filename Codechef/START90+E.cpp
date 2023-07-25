// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <pair <int, int>> segTree(mxn);
vector <vector <int>> adj(mxn);
 
void build(int l, int r, int i, vector <int> &a){
 
    if(l == r){
        segTree[i].first = a[l];
        segTree[i].second = l;
        return;
    }
 
    int mid = (l + r) / 2;
 
    build(l, mid, 2 * i + 1, a);
    build(mid + 1, r, 2 * i + 2, a);

    if(segTree[2 * i + 1].first <= segTree[2 * i + 2].first){
        segTree[i] = segTree[2 * i + 1];
    }
    else{
        segTree[i] = segTree[2 * i + 2];
    }
}
 
pair <int, int> query(int l, int r, int i, int ll, int rr){
 
    if(l > rr || r < ll) return {INT_MAX, -1};
 
    if(l >= ll && r <= rr){
        return segTree[i];
    }
 
    int mid = (l + r) / 2;

    pair <int, int> p1 = query(l, mid, 2 * i + 1, ll, rr);
    pair <int, int> p2 = query(mid + 1, r, 2 * i + 2, ll, rr);

    if(p1.first <= p2.first){
        return p1;
    }

    return p2;
}


void dfs(int root, int par, int h, vector <int> &euler, vector <int> & height){

    euler.push_back(root);
    height[root] = h;

    for(auto it : adj[root]){
        if(it != par){
            dfs(it, root, h + 1, euler, height);
            euler.push_back(root);
        }
    }    
}

int getLCA(int x, int y, vector <int> &first, vector <int> &euler, vector <int> &eulerHeight){

    pair <int, int> lca = query(0, eulerHeight.size() - 1, 0, min(first[x], first[y]), max(first[y], first[x]));
    return euler[lca.second];
}

int getDistance(int x, int y, vector <int> &first, vector <int> &euler, vector <int> &height, vector <int> &eulerHeight){

    int dx = height[x];
    int dy = height[y];

    int dlca = height[getLCA(x, y, first, euler, eulerHeight)];

    return dx + dy - 2 * dlca;
}

void buildFirst(vector <int> &f, vector <int> &v, int n){

    for(int i = 0; i < n; ++i){
        if(f[v[i]] == -1) f[v[i]] = i;
    }
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        for(int i = 0; i <= n; ++i){
            adj[i].clear();
        }
        
        for(int i = 0; i < n - 1; ++i){
            int u, v;
            cin >> u >> v;

            --u;
            --v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector <int> euler, height(n + 1, -1);
        dfs(0, -1, 0, euler, height);

        vector <int> first(n + 1, -1);
        buildFirst(first, euler, euler.size());

        vector <int> eulerHeight(euler.size());
        for(int i = 0; i < euler.size(); ++i){
            eulerHeight[i] = height[euler[i]];
        }

        for(int i = 0; i < 5 * euler.size(); ++i){
            segTree[i].first = INT_MAX;
            segTree[i].second = -1;
            adj[i].clear();
        }

        build(0, euler.size() - 1, 0, eulerHeight);

        while(q--){
            int k;
            cin >> k;

            vector <int> a(k);
            read(a, k);

            for(int i = 0; i < k; ++i) --a[i];

            if(k == 1){
                cout << 0 << "\n";
                continue;
            }

            int farthest = 0;
            int farthestNode = -1;

            int cur = a[0];

            for(int i = 0; i < k; ++i){
                int dx = getDistance(cur, a[i], first, euler, height, eulerHeight);

                if(dx >= farthest){
                    farthest = dx;
                    farthestNode = a[i];
                }
            }

            cur = farthestNode;
            int ans = 0;

            for(int i = 0; i < k; ++i){
                ans = max(ans, getDistance(cur, a[i], first, euler, height, eulerHeight));
            }

            cout << (ans + 1) / 2 << "\n";
        }
    }
    
    return 0;
}