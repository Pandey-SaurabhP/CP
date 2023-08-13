// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 205;

vector <vector <int>> adj(mxn);

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        for(int i = 0; i < mxn; ++i){
            adj[i].clear();
        }

        int n, m;
        cin >> n >> m;

        int u, v;

        for(int i = 0; i < m; ++i){
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Let us determine the ceenter first

        int centre = -1;

        for(int i = 1; i <= n; ++i){
            if(adj[i].size() == 1){
                continue;
            }

            bool ok = 1;

            

            for(auto it : adj[i]){
                if(adj[it].size() == 1){
                    // i cannot be center
                    ok = 0;
                    break;
                }
            }

            if(ok){
                centre = i;
                break;
            }
        }

        // cout << "Centre : " << centre << "\n";
        // Now we know the centre
        int x = adj[centre].size();
        int y;

        for(auto it : adj[centre]){
            y = adj[it].size() - 1;
            break;
        }

        cout << x << " " << y << "\n";

    }
    
    return 0;
}