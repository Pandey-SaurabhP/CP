#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define ff          first
#define ss          second

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

int mxn = 2e5 + 5;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

vector <vector <vector <int>>> adj(mxn);

int query(int src, int dest, int l, int par){
	if(src == dest) return 0;

	for(auto it : adj[src]){
		
		int v = it[0];
		int p = it[1];
		int cl = it[2];

		if(v == par) continue;

		int cres = query(v, dest, l, src);

		if(cres != -1){
			return (cl <= l? p + cres: cres);
		}
	}

	return -1;
}

void solve() {
    int n, q, m;
    cin >> n >> q >> m;

    vector <int> tmp;

    int ans = 0;

    while(q--){
    	int type, u, v, p, l;
    	cin >> type >> u >> v >> p >> l;

    	if(type == 1){
    		tmp = {v, p, l};
    		adj[u].pb(tmp);

    		tmp = {u, p, l};
    		adj[v].pb(tmp);
    	}
    	else{
    		swap(p, l);

    		int qq = query(u, v, l, u);

    		if(qq != -1){
    			ans ^= qq;
    		}
    	}
    }

    cout << ans << "\n";
}

int main(){
    fast();
    solve();

    return 0;
}