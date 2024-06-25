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
ll count(vector <ll> &a, ll n, ll k, map <ll, ll> &mp){

	
	vector <ll> b = a;
	
	if(n % 2 == 0){
		ll ans = 0;
		for(ll i = 0; i < n; i += 2){
			ans += (b[i + 1] - b[i]) / k;
		}
		return ans;
	}
	else{
		vector <ll> pre(n + 3, 0);
		vector <ll> suff(n + 3, 0);

		ll ans = inf;

		for(ll i = 0; i < n - 1; i += 2){
			pre[i + 2] = pre[i] + (b[i + 1] - b[i]);
			pre[i + 1] = pre[i];
		}

		for(ll i = n - 2; i >= 0; i -= 2){
			suff[i + 1] = suff[i + 3] + (b[i + 1] - b[i]);
			suff[i + 2] = suff[i + 3];
		}

		for(ll i = 0; i < n; ++i){
			// Skip ith element
			ll cans = 0;
			if(i % 2 == 0){
				cans = pre[i] + suff[i + 2];
			}
			else{
				cans = pre[i - 1] + suff[i + 2] + (b[i + 1] - b[i - 1]);
			}

			ans = min(ans, cans);
		}

		return ans / k;
	}
}

void solve() {
 	ll n, k;
 	cin >> n >> k;

 	vector <ll> a(n);
 	read(a, i, n);

 	sort(a.begin(), a.end());

 	map <ll, vector <ll>> mp;
 	map <ll, ll> cnt;

 	for(auto it : a){
 		mp[it % k].pb(it);
 		cnt[it]++;
 	}
 	

 	vector <vector <ll>> vc;
 	for(auto it : mp){
 		vc.pb(it.ss);
 	}

 	ll oddSize = 0;

 	for(auto it : vc){
 		ll sz = it.size();
 		if(sz & 1){
 			++oddSize;
 		}
 	}	

 	if(oddSize > 1){
 		cout << -1 << "\n";
 		return;
 	}

 	ll ans = 0;

 	for(auto it : mp){
 		ans += count(it.ss, it.ss.size(), k, cnt);
 	}

 	cout << ans << "\n";

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