#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
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
const ll mxn = 1e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <ll>> adj(mxn);
ll cnt = 0;

vector <pii> col(mxn);

pair <ll, ll> getAns(ll root, ll par, string &a){

	ll scnt = 0;
	ll pcnt = 0;

	for(auto it : adj[root]){
		if(it != par){

			pair <ll, ll> res = getAns(it, root, a);

			if(a[root] == 'S'){
				if(res.ss){
					++cnt;
				}
			}
			else if(a[root] == 'P'){
				if(res.ff){
					++cnt;
				}
			}
			else{ // current is C

				scnt += res.ff;
				pcnt += res.ss;
			}
		}
	}

	// cout << root << " : " << scnt + col[root].ff << " " << pcnt + col[root].ss << "\n";

	if(a[root] == 'S'){
		return {1, 0};
	}
	else if(a[root] == 'P'){
		return {0, 1};
	}
	else{
		// Either block P or S whichever is min
		if(scnt < pcnt){
			cnt += scnt;
			return {0, 1};
		}
		else if(pcnt < scnt){
			cnt += pcnt;
			return {1, 0};
		}
		else{
			scnt += col[root].ff;
			pcnt += col[root].ss;

			if(scnt < pcnt){
				cnt += scnt;
				return {0, 1};
			}
			else if(scnt >= pcnt){
				cnt += pcnt;
				return {1, 0};
			}
		}
	}
}

void dfs(int root, int par, int slp, int prt, string &s){
	if(s[root] == 'S'){
		slp = 1;
		prt = 0;
	}
	else if(s[root] == 'P'){
		slp = 0;
		prt = 1;
	}

	col[root] = {slp, prt};

	for(auto it : adj[root]){
		if(it != par){
			dfs(it, par, slp, prt, s);
		}
	}
}

void solve() {
	cnt = 0;

    ll n;
    cin >> n;

    for(ll i = 0; i < n; ++i){
    	adj[i].clear();
    	col[i] = {0, 0};
    }

    vector <ll> par(n - 1);
    read(par, i, n - 1);

    for(ll i = 0; i < n - 1; ++i){
    	adj[par[i] - 1].pb(i + 1);
    }

    string s;
    cin >> s;



    // Rooted at 0

    dfs(0, 0, 0, 0, s);

    // for(int i = 0; i < n; ++i){
    // 	cout << i << ":" << col[i].ff << " " << col[i].ss << "\n";
    // }
    getAns(0, 0, s);

    cout << cnt << "\n";
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