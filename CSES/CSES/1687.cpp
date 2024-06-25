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
const ll mxn = 2e5 + 5;
const ll lgn = 22;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int ans[mxn][lgn];
vector <vector <int>> adj(mxn);

void dfs(int root, int parent, int k, vector <int> &par){
	if(k == 0){
		ans[root][k] = par[root];
	}
	else{
		if(ans[root][k - 1] == -1){
			ans[root][k] = -1;
		}
		else ans[root][k] = ans[ans[root][k - 1]][k - 1];
	}

	for(auto it : adj[root]){
		if(it != parent){
			dfs(it, root, k, par);	
		}
	}
}

int highestPowerof2(int N){
	int num = 1;
    for(int i = 0; i < 22; ++i){
    	if(num * 2 > N){
    		return i;
    	}

    	num *= 2;
    }

    return -1;
}

int getKth(int node, int k){

	while(k){
		if(node == -1){
			return -1;
		}

		int pw = highestPowerof2(k);

		node = ans[node][pw];
		k -= pow(2, pw);
	}

	return node == -1? -1: node + 1;
}

void solve() {
	memset(ans, -1, sizeof(ans));
    	
    int n, q;
    cin >> n >> q;

    vector <int> a(n, -1);
    for(int i = 1; i < n; ++i){
    	cin >> a[i];
    	--a[i];

    	adj[a[i]].pb(i);
    }

    for(int k = 0; k < 22; ++k){
    	dfs(0, -1, k, a);
    }

    while(q--){
    	int node, k;
    	cin >> node >> k;

    	cout << getKth(node - 1, k) << "\n";
    }
}

int main(){
    
    fast();

    solve();
    return 0;
}