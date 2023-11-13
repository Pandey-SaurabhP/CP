#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

struct cmp {
public:
    bool operator()(pair <ll, pair <ll, ll>> a, pair <ll, pair <ll, ll>> b){
        if(a.first > b.first){
            return 1;
        }
        return 0;
    }
};

vector <vector <pair <ll, ll>>> adj(mxn);

ll par[mxn];
ll sz[mxn];

ll getParent(ll x){
    if(x == par[x]){
        return x;
    }

    return par[x] = getParent(par[x]);
}

void unite(ll x, ll y){
    ll px = getParent(x);
    ll py = getParent(y);

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

bool find(ll x, ll y){
    ll px = getParent(x);
    ll py = getParent(y);

    return px == py;
}

void init(){
    for(ll i = 0; i < mxn; ++i){
        par[i] = i;
        sz[i] = 1;
    }
}

void solve() {
    // Code here ->
    init();

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    read(a, n);

    set <pair <pair <ll, ll>, ll>> edges;

    for(ll i = 0; i < m; ++i){
        ll u, v;
        cin >> u >> v;

        --u; --v;

        edges.insert({{u, v}, 0});
        edges.insert({{v, u}, 0});

        adj[u].push_back({v, 0});
        adj[v].push_back({u, 0});
    }

    // Get MST using Kruskals
    vector <pair <ll, ll>> links(n);

    for(ll i = 0; i < n; ++i){
        links[i] = {a[i], i};
    }

    sort(links.begin(), links.end());

    for(ll i = 0; i < n - 1; ++i){

        ll u = links[i].second;
        ll v = links[i + 1].second;
        ll w = links[i + 1].first - links[i].first;

        edges.insert({{u, v}, w});
        edges.insert({{v, u}, w});
    }

    set <pair <ll, ll>> ans;
    ll cost = 0;

    priority_queue <pair <ll, pair <ll, ll>>, vector <pair <ll, pair <ll, ll>>>, cmp> pq;

    for(auto it : edges){
        pq.push({it.second, {it.first.first, it.first.second}});
    }


    while(!pq.empty()){
        auto tp = pq.top();
        pq.pop();

        ll u = tp.second.first;
        ll v = tp.second.second;
        ll w = tp.first;

        if(!find(u, v)){

            ans.insert({u, v});
            cost += w;

            unite(u, v);
        }
    }

    cout << cost << " " << ans.size() << "\n";
    for(auto it : ans){
        cout << it.first + 1 << " " << it.second + 1 << "\n";
    }
}

int main() {
     fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
