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

// Solve

string toStr(ll x){
	string ans = "";

	while(x){
		ans += ((x % 10) + '0');
		x /= 10;
	}

	return ans;
}

ll toBase5(ll x){
	if(x == 0) return 0;
	string ans;

	while(x){
		ans += ((x % 5) + '0');
		x /= 5;
	}

	ll aa = 0;

	ll mult = 1;

	for(ll i = 0; i < ans.size(); ++i){
		aa += (ans[i] - '0') * mult;
		mult *= 10;
	}

	--aa;
	aa *= 2;

	string tmp = toStr(aa);

	aa = 0;
	mult = 1ll;

	for(ll i = 0; i < tmp.size(); ++i){
		if((tmp[i] - '0') % 2 == 1){
			--tmp[i];
		}

		aa += (tmp[i] - '0') * mult;
		mult *= 10;
	}	

	return aa;
}

void solve() {
    ll n;
    cin >> n;

    cout << toBase5(n) << "\n";
}

int main(){
    
    fast();

    solve();
    

    return 0;
}