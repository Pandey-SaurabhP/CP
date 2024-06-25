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

vector <ll> rs;


string toStr(ll x){

	string ans;

	while(x){
		ans += (x % 10) + '0';
		x /= 10;
	}

	return ans;
}

bool isPalindrome(ll x){
	string s = toStr(x);

	ll i = 0;
	ll j = s.size() - 1;

	while(i < j){
		if(s[i] != s[j]){
			return 0;
		}

		++i;
		--j;
	}

	return 1;
}

void solve() {
 	
 	for(ll i = 1; i <= 1000000; ++i){
 		if(isPalindrome(i * i * i)){
 			rs.pb(i * i * i);
 		}
 	}

 	ll n;
 	cin >> n;

 	ll ans = 0;
 	for(auto it : rs){
 		if(it <= n){
 			ans = it;
 		}
 	}

 	cout << ans;
}

int main(){
    
    fast();

    solve();

    return 0;
}