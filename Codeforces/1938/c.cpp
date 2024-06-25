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

string toBinary(ll x){

	string ans;

	while(x){
		ans += (x % 2) + '0';
		x /= 2;
	}

	while(ans.size() != 70){
		ans += '0';
	}

	reverse(ans.begin(), ans.end());

	return ans;
}

ll getAns(ll a, ll b, ll r){
	string sa = toBinary(a);
    string sb = toBinary(b);

    ll up = 0;

    ll completed = 0;

    // cout << sa << "\n" << sb << "\n\n";

    for(ll i = 0; i < 70; ++i){
    	ll abit = sa[i] - '0';
    	ll bbit = sb[i] - '0';

    	if(abit && !bbit){
    		if(up == 0){
    			up += (1ll << (70ll - i - 1ll));
    		}
    		else{
    			ll tmp = completed + (1ll << (70ll - i - 1ll));

    			if(tmp <= r){
    				up -= (1ll << (70ll - i - 1ll));
    				completed = tmp;
    			}
    			else{
    				up += (1ll << (70ll - i - 1ll));
    			}
    		}
    	}
    	else if(!abit && bbit){
    		up -= (1ll << (70ll - i - 1ll));
    	}
    }

    return abs(up);
}

void solve() {
    ll a, b, r;
    cin >> a >> b >> r;

    if(a < b){
    	swap(a, b);
    }

    ll a1 = getAns(a, b, r);

    cout << a1 << "\n";
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