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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
stack <ll> st;
vector <bool> vis1(mxn, 0), vis2(mxn, 0), vis3(mxn, 0);
vector <vector <ll>> adj(mxn), rev(mxn);

vector <set <ll>> nw(mxn);

void dfs1(ll root){
	vis1[root] = 1;
	for(auto it : adj[root]){
		if(!vis1[it]){
			dfs1(it);
		}
	}

	st.push(root);
}

vector <vector <ll>> cmps;
vector <ll> tmp;

void dfs2(ll root){

	tmp.pb(root);
	vis2[root] = 1;

	for(auto it : rev[root]){
		if(!vis2[it]){
			dfs2(it);
		}
	}
}

ll dp[mxn];
ll getAns(ll root, vector <ll> &cost){

	if(dp[root] != -1){
		return dp[root];
	}

	ll ans = 0;
	for(auto it : nw[root]){
		if(!vis3[it]) ans = max(ans, getAns(it, cost));
	}

	return dp[root] = ans + cost[root];
} 

void solve() {

	memset(dp, -1, sizeof(dp));
    
    ll n, m;
    cin >> n >> m;

    vector <ll> a(n);
    read(a, i, n);

    rep(i, 0, m){
    	ll u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	rev[v].pb(u);
    }

    for(ll i = 0; i < n; ++i){
    	if(!vis1[i]) dfs1(i);
    }

    while(!st.empty()){
    	ll tp = st.top();
    	st.pop();

    	if(vis2[tp]){
    		continue;
    	}
    	else{
    		tmp.clear();
    		dfs2(tp);
    		cmps.pb(tmp);
    	}
    }

    vector <ll> id(n + 1, -1);

    for(ll i = 0; i < cmps.size(); ++i){
    	for(ll j = 0; j < cmps[i].size(); ++j){
    		id[cmps[i][j]] = i;
    	}
    }

    vector <ll> cost(n, 0);
    for(ll i = 0; i < n; ++i){
    	cost[id[i]] += a[i];
    }

    queue <pii> q;

    for(ll i = 0; i < n; ++i){
    	for(auto it : adj[i]){
    		if(id[i] != id[it]){
    			nw[id[i]].insert(id[it]);
    		}
    	}
    }

    ll ans = 0;

    for(ll i = 0; i < cmps.size(); ++i){
    	if(!vis3[i]){
    		ans = max(ans, getAns(i, cost));
    	}
    }

    cout << ans << "\n";
}

int main(){
    
    fast();
    solve();

    return 0;
}