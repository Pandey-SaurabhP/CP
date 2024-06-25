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

void solve() {
    ll n, c, d;
    cin >> n >> c >> d;

    ll a[n][n];

    map <ll, ll> mp;

    ll sm = INT_MAX;

    for(ll i = 0; i < n; ++i){
    	for(ll j = 0; j < n; ++j){
    		cin >> a[i][j];
    		sm = min(sm, a[i][j]);
    		mp[a[i][j]]++;
    	}
    }

    ll b[n][n];

    b[0][0] = sm;
    bool ok = 1;

    for(ll i = 1; i < n; ++i){
    	if(mp[b[0][i - 1] + d] == 0){
    		ok = 0;
    		break;
    	}
    	else{
    		b[0][i] = b[0][i - 1] + d;
    		mp[b[0][i]]--;
    	}
    }

    for(ll i = 1; i < n; ++i){
    	if(mp[b[i - 1][0] + c] == 0){
    		ok = 0;
    		break;
    	}
    	else{
    		b[i][0] = b[i - 1][0] + c;
    		mp[b[i][0]]--;

    		for(ll j = 1; j < n; ++j){
    			if(mp[b[i][j - 1] + d] == 0){
    				ok = 0;break;
    			}
    			else{
    				b[i][j] = b[i][j - 1] + d;
    				mp[b[i][j]]--;
    			}
    		}
    	}
    }

    if(ok){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
    }
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