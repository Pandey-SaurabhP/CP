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

ll counter = 0;

void dfs(ll r, ll c, vector <string> &a, vector <vector <bool>> &vis, vector <vector <ll>> &cnt, ll n, ll m){

	if(r < 0 || c < 0 || r >= n || c >= m){
		return;
	}

	if(a[r][c] != '#' || vis[r][c]){
		return;
	}

	vis[r][c] = 1;
	cnt[r][c] = counter;
	
	dfs(r, c - 1, a, vis, cnt, n, m);
	dfs(r, c + 1, a, vis, cnt, n, m);
	dfs(r + 1, c, a, vis, cnt, n, m);
	dfs(r - 1, c, a, vis, cnt, n, m);
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector <string> a(n);
    read(a, i, n);

    vector <vector <ll>> cnt(n + 1, vector <ll> (m + 1, 0));
    vector <vector <bool>> vis(n + 1, vector <bool> (m + 1, 0));

    for(ll i = 0; i < n; ++i){
    	for(ll j = 0; j < m; ++j){
    		if(!vis[i][j] && a[i][j] == '#'){
    			counter++;
    			dfs(i, j, a, vis, cnt, n, m);
    		}
    	}
    }

    map <int, int> components;
    for(int i = 0; i < n; ++i){
    	for(int j = 0; j < m; ++j){
    		components[cnt[i][j]]++;
    	}
    }
    components[0] = 0;

    int ans = 0;

    for(int i = 0; i < n; ++i){

    	// Lets fill ith row
    	// cout << i << " ";
    	set <int> st;
    	map <int, int> cmap;
    	
    	for(int j = 0; j < m; ++j){
    		if(i > 0){
    			st.insert(cnt[i - 1][j]);
    		}
    		if(i < n - 1){
    			st.insert(cnt[i + 1][j]);
    		}

    		if(cnt[i][j] != 0) cmap[cnt[i][j]]++;
    	}

    	int cans = 0;
    	for(auto it : st){
    		cans += (components[it] - cmap[it]);
    	}

    	cans += m;

    	// cout << i << " -> " << cans << "\n";
    	ans = max(ans, cans);
    }
    // cout << "\n";

    for(int i = 0; i < m; ++i){

    	// Lets fill ith row
    	// cout << i << " ";
    	set <int> st;
    	map <int, int> cmap;
    	
    	for(int j = 0; j < n; ++j){
    		if(i > 0){
    			st.insert(cnt[j][i - 1]);
    		}
    		if(i < m - 1){
    			st.insert(cnt[j][i + 1]);
    		}

    		if(cnt[j][i] != 0) cmap[cnt[j][i]]++;
    	}


    	int cans = 0;
    	for(auto it : st){
    		cans += (components[it] - cmap[it]);
    	}
    	cans += n;

    	ans = max(ans, cans);
    }

    cout << ans << "\n";
    
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