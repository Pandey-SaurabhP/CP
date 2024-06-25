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
 
vector <vector <int>> adj(mxn), rev(mxn);
stack <int> st;
vector <bool> vis(mxn, 0), visRev(mxn, 0);
 
vector <int> cmps;
 
void dfs(int root){
 
	vis[root] = 1;
	st.push(root);
 
	for(auto it : adj[root]){
		if(!vis[it]){
			dfs(it);
		}
	}
}
 
void dfsRev(int root){
 
	visRev[root] = 1;
 
	for(auto it : rev[root]){
		if(!visRev[it]){
			dfsRev(it);
		}
	}
}
 
void printSt(stack <int> st){
	cout << "St : ";
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";
}
 
void solve() {
 
    int n, m;
    cin >> n >> m;
 
    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v;
 
    	--u, --v;
 
    	adj[u].pb(v);
    	rev[v].pb(u);
    }
 	
 	dfs(0);

 	bool ok = 1;
    for(int i = 0; i < n; ++i){
    	if(!vis[i]){
    		cout << "NO\n" << 1 << " " << i + 1 << "\n";
    		return;
    		ok = 0;
    	}
    }
 
    // printSt(st);

    dfsRev(0);
    cmps.pb(0);
 
    for(int i = 0; i < n; ++i){
    	if(!visRev[i]){
    		dfsRev(i);
    		cmps.pb(i);
    		break;
    	}
    }
 
    if(cmps.size() == 1){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
    	cout << cmps[1] + 1 << " " << cmps[0] + 1 << "\n";
    }
 
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}
