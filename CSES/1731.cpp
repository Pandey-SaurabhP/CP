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

ll n, m;
ll hsh[5005][5005];
ll hashCode[100005];
string a[100005];	
ll sz[100005];

ll dp[5005];

ll getHash(string s){
	ll ans = 0ll;
	ll mult = 1ll;
	ll x = s.size();

	for(ll i = 0; i < x; ++i){
		ans += (mult * (s[i] - 'a')) % mod;
		ans %= mod;

		mult *= 26ll;
		mult %= mod;
	}

	return ans;
}

bool match(ll i, ll j){
	if(i + sz[j] > m){
		return 0;
	}

	return (hashCode[j] == hsh[i][i + sz[j] - 1]);
}

ll slv(ll i){
	if(i > m){
		return 0;
	}
	else if(i == m){
		return 1;
	}
	else{
		if(dp[i] != -1){
			return dp[i];
		}

		ll ans = 0;

		for(ll j = 0; j < n; ++j){
			if(match(i, j)){
				ans += slv(i + sz[j]);
				ans %= mod;
			}
		}

		return dp[i] = ans % mod;
	}
}

void solve() {
	memset(dp, -1ll, sizeof(dp));
    
    string s;
    cin >> s;

    m = s.size();

    for(ll i = 0ll; i < m; ++i){
    	ll mult = 1ll;

    	for(ll j = i; j < m; ++j){
    		hsh[i][j] = (j - 1ll >= 0ll? hsh[i][j - 1]: 0ll) + ((s[j] - 'a') * mult) % mod;
    		hsh[i][j] %= mod;

    		mult *= 26ll;
    		mult %= mod;
    	}
    }

    cin >> n;
    read(a, i, n);

    for(ll i = 0; i < n; ++i){
    	hashCode[i] = getHash(a[i]);
    	sz[i] = a[i].size();
    }

    cout << slv(0);
}

int main(){
    
    fast();
    solve();

    return 0;
}