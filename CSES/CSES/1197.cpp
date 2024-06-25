#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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
const ll mxn = 2501;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
vector <pair <ll, pii>> edges;

void solve() {
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; ++i){
    	ll u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;


    	edges.pb({w, {u, v}});
    }

    vector <ll> d(n, INT_MAX);
    vector <ll> p(n, -1);

    d[0] = 0;

    for(ll i = 0; i < n; ++i){

    	for(ll j = 0; j < m;  ++j){


    		ll u = edges[j].ss.ff;
    		ll v = edges[j].ss.ss;
    		ll w = edges[j].ff;

    		if(d[v] > d[u] + w){
    			d[v] = d[u] + w;
    		}
    	}
    }

    vector <ll> d2 = d;

    for(ll i = 0; i < n; ++i){

    	for(ll j = 0; j < m;  ++j){
    		ll u = edges[j].ss.ff;
    		ll v = edges[j].ss.ss;
    		ll w = edges[j].ff;

    		if(d2[v] > d2[u] + w){
    			d2[v] = d2[u] + w;
    			p[v] = u;
    		}
    	}
    }

    ll x = -1;
    for(int i = 0; i < n; ++i){
    	if(p[i] != -1){
    		x = p[i]; break;
    	}
    }

    if(x == -1){
    	cout << "NO\n";
    }
    else{
    	cout << "YES\n";


        for(int i = 0; i < n; ++i){
            x = p[x];
        }

    	vector <ll> ans;
    	
    	vector <bool> vis(n, 0);

    	while(!vis[x]){
    		ans.pb(x + 1);
    		vis[x] = 1;
    		x = p[x];
    	}
    	ans.pb(ans[0]);

    	reverse(ans.begin(), ans.end());
    	// ans.pb(ans[0]);

    	print(ans, i, ans.size());

	}
 
}

int main(){
    
    // fast();

    solve();

    return 0;
}