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

vector <pii> mp[1000005];

void solve() {
    ll n, t;
    cin >> n >> t;

    vector <ll> a(n);
    read(a, i, n);


    for(ll i = 0; i < n; ++i){
    	for(ll j = i + 1; j < n; ++j){
    		if(a[i] + a[j] <= t) mp[a[i] + a[j]].pb({i, j});
    	}
    }

    ll ans = 0;

    for(int i = 0; i < n; ++i){
    	for(int j = i + 1; j < n; ++j){
    		int csum = a[i] + a[j];

    		if(csum > t) continue;

    		int rsum = t - csum;

    		for(auto it : mp[rsum]){
    			int x = it.ff;
    			int y = it.ss;

    			if(x > i && x < j && y > i && y < j){
    				++ans;
    			}
    		}
    	}
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}