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
vector <int> aa;
vector <bool> vis2(mxn, 0);
 
bool isCycle(int root, bool fnd){
	if(vis2[root]) return 0;
 
	vis[root] = 1;
	vis2[root] = 1;
 
	aa.pb(root);
 
	bool ans = 0;
 
	for(auto it : adj[root]){
		if(fnd){
			if(vis[it]){
				aa.pb(it);
				return 1;
			}
			else{
				ans |= isCycle(it, 1);
			}
 
			if(ans) return 1;
		}
		else{
			if(!vis[it]){
				ans |= isCycle(it, 1);
 
				if(ans) return 1;
			}
		}
	}
 
	aa.pop_back();
	vis[root] = 0;
 
	return ans;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    for(int i = 0; i <= n; ++i){
    	vis[i] = 0;
    }
 
    for(int i = 0; i < m; ++i){
    	int a, b;
    	cin >> a >> b;
 
    	adj[a].pb(b);
    }
 
    bool ok = 0;
 
    for(int i = 1; i <= n; ++i){
    	if(!vis2[i]){
    		aa.clear();
 
    		if(isCycle(i, 0)){
    			ok = 1;
    			break;
    		}
    	}
    }
 
    if(ok){
 
    	int lst = aa[aa.size() - 1];
 
    	// print(aa, i, aa.size());
 
    	vector <int> nans;
    	nans.pb(aa[aa.size() - 1]);
 
    	for(int i = aa.size() - 2; i >= 0; --i){
    		if(aa[i] == lst){
    			nans.pb(aa[i]);
    			break;
    		}
    		else{
    			nans.pb(aa[i]);
    		}
    	}
 
    	reverse(nans.begin(), nans.end());
    	cout << nans.size() << "\n";
    	print(nans, i, nans.size());
    }
    else{
    	cout << "IMPOSSIBLE";
    }
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}