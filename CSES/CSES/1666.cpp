#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5+ 5;

int par[mxn];
int sz[mxn];

int getParent(int x){
    if(x == par[x]){
        return x;
    }

    return par[x] = getParent(par[x]);
}

void unite(int x, int y){
    int px = getParent(x);
    int py = getParent(y);

    if(px != py){
        if(sz[px] >= sz[py]){
            par[py] = px;
            sz[px] += sz[py];
        }
        else{
            par[px] = py;
            sz[py] += sz[px];
        }
    }
}

bool find(int x, int y){
    int px = getParent(x);
    int py = getParent(y);

    return px == py;
}

int main(){

    for(int i = 0; i < mxn; ++i){
        par[i] = i;
        sz[i] = 1;
    }
    int n, m;
    cin >> n >> m;

    while(m--){
        int x, y;
        cin >> x >> y;

        unite(x, y);
    }

    for(int i = 1; i <= n; ++i){
        getParent(i);
    }

    map <int, int> mp;
    for(int i = 1; i < n + 1; ++i){
        mp[par[i]] = i;
    }

    vector <pair <int, int>> vc;

    for(auto it : mp){
        vc.push_back({it.first, it.second});
    }

    vector <pair <int, int>> ans;

    cout << vc.size() - 1 << "\n";

    for(int i = 1; i < vc.size(); ++i){
        cout << vc[i - 1].first << " " << vc[i].first << "\n";
    }


    return 0;
}
