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

ll dfs(ll i, ll j, vector <vector <ll>> &a, ll &n, ll &m, vector <vector <bool>> &vis){

    if(a[i][j] == 0) return 0;

    vis[i][j] = 1;

    ll ans = a[i][j];

    if(i + 1 < n && !vis[i + 1][j]) ans += dfs(i + 1, j, a, n, m, vis);
    if(i - 1 >= 0 && !vis[i - 1][j]) ans += dfs(i - 1, j, a, n, m, vis);
    if(j + 1 < m && !vis[i][j + 1]) ans += dfs(i, j + 1, a, n, m, vis);
    if(j - 1 >= 0 && !vis[i][j - 1]) ans += dfs(i, j - 1, a, n, m, vis);

    return ans;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, m;
        cin >> n >> m;

        vector <vector <ll>> a(n, vector <ll> (m));

        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < m; ++j){
                cin >> a[i][j];
            }
        }

        vector <vector <bool>> vis(n, vector <bool> (m, 0));

        ll ans = 0;

        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < m; ++j){
                if(!vis[i][j]){
                    ans = max(ans, dfs(i, j, a, n, m, vis));
                }
            }
        }

        cout << ans << "\n";

    }
    
    return 0;
}