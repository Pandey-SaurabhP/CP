#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
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

map <pii, vector <pii>> adj;

int ans[9][9];
int cnt = 1;

bool slv(int x, int y, set <pii> &st){
 
	ans[x][y] = cnt;
 
	if(st.size() == 64){
		return 1;
	}

 
	bool ans = 0;
 
	for(auto it : adj[{x, y}]){
		pii xyz = it;
 
		if(!st.count(it)){
			st.insert(it);
			++cnt;
 
			ans |= slv(xyz.ff, xyz.ss, st);
 
			if(ans) return 1;
 
			--cnt;
 
			st.erase(it);
		}
	}
 
	return 0;
}

void solve() {
    	
    int x, y;
    cin >> x >> y;


    for(int i = 1; i <= 8; ++i){
    	for(int j = 1; j <= 8; ++j){

    		vector <pii> xyz(8);

    		xyz[0] = {i - 2, j - 1};
    		xyz[1] = {i - 1, j - 2};
    		xyz[2] = {i + 1, j - 2};
    		xyz[3] = {i + 2, j - 1};
    		xyz[4] = {i - 2, j + 1};
    		xyz[5] = {i - 1, j + 2};
    		xyz[6] = {i + 1, j + 2};
    		xyz[7] = {i + 2, j + 1};

    		for(int k = 0; k < 8; ++k){
    			if( xyz[k].ff >= 1 && xyz[k].ff <= 8 &&
    				xyz[k].ss >= 1 && xyz[k].ss <= 8 ){

    				adj[{i, j}].pb(xyz[k]);
    			}
    		}

    		
    	}
    }

    for(int i = 1; i <= 8; ++i){
    	for(int j = 1; j <= 8; ++j){
    		sort(adj[{i, j}].begin(), adj[{i, j}].end(), [](pii x, pii y){
    			return (adj[x].size() < adj[y].size());
    		} );
    	}
    }

    // for(int i = 1; i <= 8; ++i){
    // 	for(int j = 1; j <= 8; ++j){
    // 		cout << i << " " << j << " : ";

    // 		for(auto it : adj[{i, j}]){
    // 			cout << it.ff << " " << it.ss << "   ";
    // 		}
    // 		cout <<"\n";

    // 	}
    // }
    		

    set <pii> st;
    st.insert({x, y});

    // cout << slv(x, y, st) << "\n";
    slv(x, y, st);

    for(int i = 1; i <= 8; ++i){
    	for(int j = 1; j <= 8; ++j){
    		cout << ans[j][i] << " ";
    	}
    	cout << "\n";
    }


}

int main(){
    
    fast();
    solve();

    return 0;
}