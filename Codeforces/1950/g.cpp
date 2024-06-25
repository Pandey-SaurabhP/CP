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

int filled(int x){
	int ans = 0;
	while(x){
		ans += (x & 1);
		x >>= 1;
	}

	return ans;
}

int dp[17][17][1 << 16];

int slv(int last, int i, int bits, vector <pii> &a){
	// cout << bits << "\n";
	if(i == a.size()){
		return filled(bits);
	}

	if(dp[last][i][bits] != -1) return dp[last][i][bits];

	int a1 = filled(bits);

	rep(j, 0, a.size()){
		if(!(bits & (1 << j))){
			// Pick it or leave it
			if(a[j].ff == a[last].ff || a[j].ss == a[last].ss){
				a1 = max(slv(j, i + 1, bits | (1 << j), a), a1);
			}
		}
	}

	return dp[last][i][bits] = a1;
}

void solve() {
    int n;
    cin >> n;

    rep(i, 0, n + 1){
    	rep(j, 0, n + 1){
    		rep(k, 0, (1 << n)){
    			dp[i][j][k] = -1;
    		}
    	}
    }
    vector <string> v1(n), v2(n);

    cin.clear();

    rep(i, 0, n){
    	cin >> v1[i] >> v2[i];
    }


    map <string, int> mp1, mp2;

    int x = 0, y = 0;

    rep(i, 0, n){
    	// cout << v1[i] << " " << v2[i] << "\n";
    	if(!mp1.count(v1[i])){
    		mp1[v1[i]] = x++;
    	}
    	if(!mp2.count(v2[i])){
    		mp2[v2[i]] = y++;
    	}
    }

    // cout << "Hello!\n";

    vector <pii> a(n);

    rep(i, 0, n){
    	a[i] = {mp1[v1[i]], mp2[v2[i]]};
    }

    int gans = 0;
    rep(i, 0, n){
    	gans = max(gans, slv(i, 0, (1 << i), a));
    }

    cout << n - gans << "\n";

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