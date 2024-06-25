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

vector <vector <int>> adj(mxn);
vector <int> cntc(mxn, 0);
vector <int> mxc(mxn, 0);

int n;

int getChildren(int root, int par){

	int cnt = 0;
	int mx = 0;

	for(auto it : adj[root]){
		if(it != par){
			int tmp = getChildren(it, root);
			cnt += tmp;
			mx = max(mx, tmp);
		}
	}

	mxc[root] = mx;
	return cntc[root] = 1 + cnt;
}

int ans = -1;

void getAns(int root, int par){
	if(root == 0){
		if(mxc[root] <= n / 2){
			ans = root;
		}
	}
	else{
		int one = mxc[root];
		int two = n - cntc[root];

		// cout << root << " : " << one << " " << two << "\n";

		if(max(one, two) <= n / 2){
			ans = root;
		}
	}

	for(auto it : adj[root]){
		if(it != par){
			getAns(it, root);
		}
	}
}

void solve() {
    
    cin >> n;

    for(int i = 0; i < n - 1; ++i){
    	int u, v;
    	cin >> u >> v;

    	--u, --v;

    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    getChildren(0, 0);

    // print(cntc, i, n);
    // print(mxc, i, n);

    getAns(0, 0);

    cout << ans + 1;
}

int main(){
    
    fast();

    solve();

    return 0;
}