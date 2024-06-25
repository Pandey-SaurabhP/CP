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

bool memo[100005][513];
bool done[100005][513];
	
bool slv(int i, int e, vector <int> &a, int n, set <int> &target){

	if(i == n){

		if(target.count(e)){
			return 1;
		}

		return 0;
	}

	if(done[i][e]){
		return memo[i][e];
	}

	bool a1 = slv(i + 1, e, a, n, target);
	bool a2 = slv(i + 1, e ^ a[i], a, n, target);

	done[i][e] = 1;
	return memo[i][e] = a1 | a2;
}


void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    for(int i = 0; i <= n; ++i){
    	for(int j = 0; j < 513; ++j){
    		memo[i][j] = 0;
    		done[i][j] = 0;
    	}
    }

    --a, --b;

    set <int> st;
    set <int> target;

    for(int i=  0; i < n - 1; ++i){
    	int u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;

    	if(u == b || v == b){
    		target.insert(w);
    	}
    	else st.insert(w);
    }

    vector <int> tmp;

    for(auto it : st){
    	tmp.pb(it);
    }

    bool ans = slv(0, 0, tmp, tmp.size(), target);

    if(ans){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
    }
}

int main(){
    
    // fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}