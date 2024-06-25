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
const ll mxn = 1e2 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll res[mxn][mxn];
ll par[mxn];

bool bfs(ll src, ll target){

	queue <ll> q;
	q.push(src);
	par[src] = -1;

	bool vis[mxn];
	memset(vis, 0, sizeof(vis));
	vis[src] = 1;

	ll mn = INT_MAX;

	while(!q.empty()){
		ll tp = q.front();
		q.pop();

		for(ll i = 0; i < mxn; ++i){
			if(!vis[i] && res[src][i] != INT_MIN){
				// There's a valid way
				vis[i] = 1;
				par[i] = tp;
				q.push(i);

				if(i == target){
					return 1;
				}
			}
		}
	}

	return 0;
}

ll ff(ll src, ll target){

	ll ans = 0;

	while(bfs(src, target)){

		ll mn = INT_MAX;
		for(ll i = target; par[i] != -1; i = par[i]){
			mn = min(mn, res[par[i]][i]);
		}

		for(ll i = target; par[i] != -1; i = par[i]){
			res[par[i]][i] -= mn;
			res[i][par[i]] += mn;
		}

		ans += mn;
	}

	return ans;
}

void solve() {
	for(ll i = 0; i < mxn; ++i){
		for(ll j = 0; j < mxn; ++j){
			res[i][j] = INT_MIN;
		}
	}

    ll n, m;
    cin >> n >> m;

    vector <ll> a(n), b(m);
    read(a, i, n);
    read(b, i, m);

    vector <ll> sm(n, 0);

    for(ll i = 0; i < n; ++i){
    	ll cnt;
    	cin >> cnt;

    	for(ll j = 0; j < cnt; ++j){
    		ll x;
    		cin >> x;

    		sm[i] += b[x - 1];
    	}

    	sm[i] *= -1;
    }


    for(ll i = 0; i < n; ++i){
    	res[0][i + 1] = INT_MAX;
    }

    for(ll i = 0; i < n; ++i){
    	res[i + 1][n + i + 1] = sm[i];
    	res[n + i + 1][2 * n + 1] = a[i];
    }


    for(int i = 0; i <= 2 * n + 1; ++i){
    	for(int j = 0; j <= 2 * n + 1; ++j){
    		cout << res[i][j] << " ";
    	}
    	cout << "\n";
    }

    cout << ff(0, 2 * n + 1) << "\n";
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