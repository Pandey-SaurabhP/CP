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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}


// DSU
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

// Solve

bool intersecting(pair <pii, ll> a, pair <pii, ll> b){
	ll d = (a.ff.ff - b.ff.ff) * (a.ff.ff - b.ff.ff);
	d += (a.ff.ss - b.ff.ss) * (a.ff.ss - b.ff.ss);

	if(d <= (a.ss + b.ss) * (a.ss + b.ss)){
		return 1;
	}

	return 0;
}

void solve() {
	for(ll i = 0; i < mxn; ++i){
        par[i] = i;
        sz[i] = 1;
    }

 	ll n, m, k;
 	cin >> n >> m >> k;

 	vector <pair <pii, ll>> a(k);

 	for(ll i = 0; i < k; ++i){
 		ll x, y, r;
 		cin >> x >> y >> r;

 		a[i] = {{x, y}, r};
 	}   


 	for(ll i = 0; i < k; ++i){
 		for(ll j = i + 1; j < k; ++j){
 			if(intersecting(a[i], a[j])){
 				unite(i, j);
 			}
 		}
 	}


 	map <ll, vector <pair <pii, ll>>> mp;

 	for(ll i = 0; i < k; ++i){
 		mp[getParent(i)].push_back(a[i]);
 	}

 	bool ok = 1;

 	for(int i = 0; i < k; ++i){
 		if(intersecting({{0ll, 0ll}, 0ll}, a[i])){
 			ok = 0;
 		}
 		if(intersecting({{n, m}, 0ll}, a[i])){
 			ok = 0;
 		}
 	}

 	for(ll i = 0; i < k; ++i){
 		if(mp.count(i)){
 			// Find max and min x
 			ll mny = mp[i][0].ff.ff - mp[i][0].ss;
 			ll mxy = mp[i][0].ff.ff + mp[i][0].ss;

 			for(auto it : mp[i]){
 				mny = min(mny, it.ff.ff - it.ss);
 				mxy = max(mxy, it.ff.ff + it.ss);
 			}

 			ll mnx = mp[i][0].ff.ss - mp[i][0].ss;
 			ll mxx = mp[i][0].ff.ss + mp[i][0].ss;

 			for(auto it : mp[i]){
 				mnx = min(mnx, it.ff.ss - it.ss);
 				mxx = max(mxx, it.ff.ss + it.ss);
 			}

 			if(mnx <= 0 && mxx >= m){
 				ok = 0;
 				break;
 			}

 			if(mny <= 0 && mxy >= n){
 				ok = 0;
 				break;
 			}

 			if(mnx <= 0 && mny <= 0){
 				ok = 0;
 				break;
 			}

 			if(mxx >= m && mxy >= n){
 				ok = 0;
 				break;
 			}


 		}
 	}

 	if(ok){
 		cout << "S";
 	}
 	else{
 		cout << "N";
 	}

}

int main(){
    
    fast();
    solve();

    return 0;
}