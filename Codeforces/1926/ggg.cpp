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

const ll inf = INT_MAX;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <vector <ll>> adj(mxn);

ll slv(ll root, ll par, ll type, string &s){

	if(type == 0 && s[root] != 'S'){
		return inf;
	}

	if(type == 1 && s[root] != 'P'){
		return inf;
	}

	if(type == 2 && s[root] != 'C'){
		return inf;
	}

	ll ans = 0;
	// 0 - sleep, 1 - party, 2 - careless

	bool ran = 0;

	for(auto it : adj[root]){
		if(it != par){

			ll xyz = inf;

			xyz = min(xyz, (s[root] == 'P') + slv(it, root, 0, s));
			xyz = min(xyz, (s[root] == 'S') + slv(it, root, 1, s));
			xyz = min(xyz, slv(it, root, 2, s));

			ans += xyz;

			ran = 1;
		}
	}

	if(!ran){
		if(type == 0 && s[root] == 'S'){
			return 0;
		}

		if(type == 1 && s[root] == 'P'){
			return 0;
		}

		if(type == 2 && s[root] == 'C'){
			return 0;
		}

		return inf;
	}

	return ans;
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n - 1);
    read(a, i, n - 1);

    for(ll i = 0; i < n - 1; ++i){
    	adj[a[i] - 1].pb(i + 1);
    }

    string s;
    cin >> s;

    cout << min(slv(0, 0, 0, s), min(slv(0, 0, 1, s), slv(0, 0, 2, s))) << "\n";
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