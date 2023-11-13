#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 5;
vector <vector <int>> adj(mxn);

vector <int> disc(mxn, -1);
vector <int> mini(mxn, -1);

vector <bool> inStack(mxn, 0);

stack <int> st;

int curTime = 0;

vector <vector <int>> components;
set <int> condensed;

void tarjans(int root){

    disc[root] = ++curTime;
    mini[root] = disc[root];

    st.push(root);
    inStack[root] = 1;

    for(auto it : adj[root]){

        if(disc[it] == -1){
            tarjans(it);
            mini[root] = min(mini[root], mini[it]);
        }
        else{
            if(inStack[it]) mini[root] = min(mini[root], disc[it]);
        }
    }

    vector <int> tmp;

    if(disc[root] == mini[root]){
        while(st.top() != root){
            int tp = st.top();
            st.pop();
            tmp.push_back(tp);
            inStack[tp] = 0;
        }

        int tp = st.top();
        st.pop();
        condensed.insert(tp);
        tmp.push_back(tp);
        inStack[tp] = 0;
    }

    components.push_back(tmp);
}

vector <int> in(mxn, 0);
vector <int> out(mxn, 0);
vector <bool> vis(mxn, 0);

void inout(int root){
    vis[root] = 1;

    for(auto it : adj[root]){
        if(condensed.count(it)){
            in[it] = 1;
            out[root] = 1;

            if(!vis[it]) inout(it);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
    }

    for(int i = 1; i <= n; ++i){
        if(disc[i] == -1){
            tarjans(i);
        }
    }

    for(auto it : condensed){
        if(!vis[it]){
            inout(it);
        }
    }

    int inzero, outzero;
    inzero = outzero = 0;

    for(auto i : condensed){
        if(in[i] == 0){
            ++inzero;
        }
        if(out[i] == 0){
            ++outzero;
        }
    }

    if(condensed.size() == 1){
        cout << 0;
    }
    else cout << max(inzero, outzero);

    return 0;
}
