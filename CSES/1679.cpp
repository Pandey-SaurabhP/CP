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
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <int>> adj(mxn);
vector <bool> vis(mxn, 0);
vector <int> in(mxn, 0);

void dfs(int root){

	vis[root] = 1;

	for(auto it : adj[root]){
		in[it]++;

		if(!vis[it]){
			dfs(it);
		}
	}
}

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    }


    for(int i = 0; i < n; ++i){
    	if(!vis[i]){
    		dfs(i);
    	}
    }

    map <int, int> mp;

    for(int i = 0; i < n; ++i){
    	mp[i] = in[i];
    }

    queue <int> q;

    for(int i = 0; i < n; ++i){
    	if(in[i] == 0){
    		q.push(i);
    	}
    }

    vector <int> ans;

    while(!q.empty()){
    	int tp = q.front();
    	q.pop();

    	ans.pb(tp + 1);

    	for(auto it : adj[tp]){
    		in[it]--;

    		if(in[it] == 0){
    			q.push(it);
    		}
    	}
    }

    bool ok = 1;
    for(auto it : in){
    	if(it != 0){
    		ok = 0;
    		break;
    	}
    }

    if(!ok){
    	cout << "IMPOSSIBLE";
    	return;
    }

    print(ans, i, ans.size());
}

int main(){
    
    fast();

    solve();

    return 0;
}