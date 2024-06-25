#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
vector< pair<int, int> > adj[mxn + 10];

int n, a, b;

int vala[mxn + 10];
int valb[mxn + 10];

void DFS(int u, int val, int p)
{
    vala[u] = val;
    for (auto v: adj[u])
    {
        if (v.first == p) continue;
        if (v.first == b) continue;
        DFS(v.first, val ^ v.second, u);
    }
}
 
void DFSb(int u, int val, int p)
{
    valb[u] = val;
    for (auto v: adj[u])
    {
        if (v.first == p) continue;
        DFSb(v.first, val ^ v.second, u);
    }
}

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++){
    	adj[i].clear();
    }
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    for (int i = 1; i <= n; i++) vala[i] = -1;
    for (int i = 1; i <= n; i++) valb[i] = 0;
    DFS(a, 0, -1);
    DFSb(b, 0, -1);

    if (vala[b] == 0) cout << "YES" << endl;
    else
    {
        set<int> s;
        for (int i = 1; i <= n; i++)
            if (vala[i] != -1) s.insert(vala[i]);
        bool ok = false;
        for (int i = 1; i <= n; i++)
            if (i != b)
            if (s.find(valb[i]) != s.end())
            {
                ok = true;
                break;
            }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}