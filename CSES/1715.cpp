#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
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

ll fastPower(ll b, ll e){

	ll ans = 1;

	while(e){
		if(e & 1){
			ans *= b;
			ans %= mod;
			--e;
		}
		else{
			b *= b;
			b %= mod;
			e >>= 1;
		}
	}

	return ans;
}

ll mmi(ll x){
	return fastPower(x, mod - 2);
}

ll fact(ll x){
	ll ans = 1;

	for(ll i = 1; i <= x; ++i){
		ans *= i;
		ans %= mod;
	}

	return ans;
}

void solve() {
    string s;
    cin >> s;


    vector <ll> cnt(256, 0);

    for(auto it : s){
    	cnt[it]++;
    }

    ll ans = fact(s.size());

    for(ll i = 'a'; i <= 'z'; ++i){
    	if(cnt[i] == 0) continue;
    	ans *= mmi(fact(cnt[i]));
    	ans %= mod;
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}