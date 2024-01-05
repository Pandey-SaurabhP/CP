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
const ll mxn = 3e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <int>> adj(mxn);
set <int> st;

int dfs(int root, string &s){

	if(st.count(root)){
		return 0;
	}

	int ans = INT_MAX;

	int i = 0;

	for(auto it : adj[root]){
		if(it == -1){
			++i;
			continue;
		}
		else{
			ans = min(ans, (i == 0? (s[root] != 'L'): (s[root] != 'R')) + dfs(it, s));
			++i;
		}
	}

	return ans;
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i <= n; ++i){
    	adj[i].clear();
    }
    st.clear();

    string s;
    cin >> s;

    for(int i = 0; i < n; ++i){
    	int l, r;
    	cin >> l >> r;

    	--l; --r;

		adj[i].pb(l);
		adj[i].pb(r);
    	

    	if(l == -1 && r == -1){
    		st.insert(i);
    	}
    }

    cout << dfs(0, s) << "\n";
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