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

ll getAns(ll root, ll par, ll slp, ll prt, string &s){

	if(s[root] == 'S' && prt) return INT_MAX;
	if(s[root] == 'P' && slp) return INT_MAX;

	ll ans = 0;

	for(auto it : adj[root]){
		if(it != par){

			// Either mark the edge from u to v, or leave it

			// Mark
			ll a1 = 1 + getAns(it, root, 0, 0, s);

			// Leave
			ll a2 = getAns(it, root, slp | (s[root] == 'S'), prt | (s[root] == 'P'), s);

			ans += min(a1, a2);
		}
	}

	return ans;
}

void solve() {
	cnt = 0;

    ll n;
    cin >> n;

    for(ll i = 0; i < n; ++i){
    	adj[i].clear();
    }

    vector <ll> par(n - 1);
    read(par, i, n - 1);

    for(ll i = 0; i < n - 1; ++i){
    	adj[par[i] - 1].pb(i + 1);
    }

    string s;
    cin >> s;

    cout << getAns(0, 0, 0, 0, s) << "\n";
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