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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll par[mxn];
ll sz[mxn];
 
ll getParent(ll x){
    if(x == par[x]){
        return x;
    }
 
    return par[x]  = getParent(par[x]);
}
 
void unite(ll x, ll y){
    ll px = getParent(x);
    ll py = getParent(y);
 
    if(px != py){
        if(sz[px] >= sz[py]){
            par[py] = px;
            sz[px] += sz[py];
        }
        else{
            par[px] = py;
            sz[py] += sz[px];
        }
    }
}
 
bool find(ll x, ll y){
    ll px = getParent(x);
    ll py = getParent(y);
 
    return px == py;
}

void solve() {

	for(ll i = 0; i <= mxn; ++i){
		sz[i] = 1;
		par[i] = i;
	}
    ll n, m;
    cin >> n >> m;

    ll cnt = n;
    ll mx = 1;

    for(ll i = 0; i < m; ++i){
    	ll u, v;
    	cin >> u >> v;

    	if(!find(u, v)){
    		unite(u, v);
    		mx = max(sz[getParent(u)], mx);
    		--cnt;
    	}



    	cout << cnt << " " << mx << "\n";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}