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
const ll inf = 1e18;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll mn = inf;

ll checkVal(string &s){

	vector <ll> integers;
	vector <ll> operations;

	for(ll i = 0; i < s.size(); ++i){
		if(s[i] == '+' || s[i] == 'x'){
			operations.pb((s[i] == '+'? 0: 1));
		}
		else{
			ll tmp = s[i] - '0';
			if(i + 1 < s.size()){
				if(s[i + 1] >= '0' && s[i + 1] <= '9'){
					tmp = tmp * 10 + (s[i + 1] - '0');
				}
			}

			integers.pb(tmp);
		}
	}

	ll res = 0;

	
	ll r = integers[0];
	for(ll i = 0; i < operations.size(); ++i){
		if(operations[i] == 0){
			res += r;
			r = integers[i + 1];
		}
		else{
			r *= integers[i + 1];
		}
	}
	res += r;

	// cout << s << "\n";
	// print(integers, i, integers.size());
	// print(operations, i, operations.size());

	return res;	
}

ll stn;

void slv(ll i, ll n, bool twoDone, string &s, string &p){

	if(p.size() == s.size() + stn){
		// OK
		// Check the value
		// mn = min(mn, checkVal(p));

		if(twoDone){
			mn = min(mn, checkVal(p));
		}
		return;
	}

	if(p[p.size() - 1] != '+' && p[p.size() - 1] != 'x' && i != 0){
		// Add a sign
		p += '+';
		slv(i, n - 1, twoDone, s, p);
		p.pop_back();

		p += 'x';
		slv(i, n - 1, twoDone, s, p);
		p.pop_back();
	}
	else{
		if(!twoDone){
			p += s[i];
			p += s[i + 1];

			slv(i + 2, n, 1, s, p);

			p.pop_back();
			p.pop_back();
		}

		p += s[i];
		slv(i + 1, n, twoDone, s, p);
		p.pop_back();
	}
}

ll slv3(vector <ll> nums, ll sz){


	ll ans = 0;
	ll r = nums[0];

	if(r == 0) return 0;
	for(ll i = 1; i < nums.size(); ++i){
		if(nums[i] == 0) return 0;
		if(r == 1 || nums[i] == 1){
			r *= nums[i];
		}
		else{
			ans += r;
			r = nums[i];
		}

		// cout << i << " " << ans << " " << r << "\n";
	}

	ans += r;

	// print(nums, i, sz);
	// cout << " -> " << ans << "\n";
	return ans;
}

ll slv2(string s, ll n){

	if(n <= 2){
		int xyz = (s[0] - '0') * 10;
		xyz += (s[1] - '0');

		return xyz;
	}

	ll ans = inf;

	for(ll i = 0; i < n - 1; ++i){
		// Make this element as two

		vector <ll> tmp;

		for(ll j = 0; j < n; ++j){
			if(j == i){
				ll xyz = (s[j] - '0') * 10;
				xyz += (s[j + 1] - '0');
				++j;
				tmp.pb(xyz);
			}
			else{
				tmp.pb(s[j] - '0');
			}
		}


		ans = min(ans, slv3(tmp, tmp.size()));
	}

	return ans;
}

void solve() {
    ll n; cin >> n;
    string s;
    cin >> s;

    cout << slv2(s, n) << "\n";
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