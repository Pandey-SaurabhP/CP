// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main(){

    // fast();

    int n, m;
    cin >> n >> m;

    vector <int> a(n);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    while(q--){
        int type, x;
        cin >> type >> x;

        if(type == 1){
            // Query

        }
        else{
            // Upward shift
            
        }
    }


    
    return 0;
}