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
#define read(a, i, n) for(ll i = 0ll; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0ll; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 998244353;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0ll); cout.tie(0ll);
}

ll fastPower(ll b, ll e){

	if(e < 0) return 1;
	ll ans = 1ll;

	while(e){
		if(e & 1ll){
			ans *= b;
			ans %= mod;
			--e;
		}
		else{
			b *= b;
			b %= mod;
			e >>= 1ll;
		}
	}

	return ans % mod;
}

ll getMx(vector <ll> &a, ll n){
	vector <ll> pre(n + 1, 0);

    ll mn = a[0];
    ll mnId = 0;
    for(ll i = 0; i < n; ++i){
    	pre[i + 1] = pre[i] + a[i];

    	if(pre[i + 1] <= mn){
    		mn = pre[i + 1];
    		mnId = i;
    	}
    	
    }

    // Found the min val
    // cout << "mn : " << mnId << "\n";

    if(mn >= 0){
    	// cout << abs(pre[n]) << "\n";
    	return abs(pre[n]);
    }
    else{
    	ll ans = abs(pre[mnId + 1]);

    	for(ll i = mnId + 1; i < n; ++i){
    		ans += a[i];
    	}

    	// cout << abs(ans) << "\n";
    	return abs(ans);
    }
}

ll slv2(vector <ll> &a, ll n){
	vector <ll> pre(n + 1ll, 0ll);
    vector <ll> pcnt(n + 1ll, 0ll);

    ll mn = a[0ll];
    ll mnId = 1ll;

    for(ll i = 0ll; i < n; ++i){
    	pre[i + 1ll] = pre[i] + a[i];
    	pcnt[i + 1ll] = pcnt[i] + (pre[i + 1ll] >= 0ll);

    	if(pre[i + 1ll] < mn){
    		mn = pre[i + 1ll];
    		mnId = i + 1ll;
    	}
    }

    if(mn >= 0ll){
    	ll ans = fastPower(2ll, n) % mod;
    	// cout << ans << "\n";
    	return ans % mod;
    }

    ll mnCnt = 0ll; bool start = 0ll; ll cnt = 0ll;
    for(ll i = 1ll; i <= n; ++i){
    	mnCnt += (pre[i] == mn);
    }

    ll ans = 0ll;
    for(ll i = 1; i <= n; ++i){
    	if(pre[i] == mn){
    		// cout << "Hello\n";
    		ll cans = 1ll;

    		cans *= fastPower(2ll, pcnt[i - 1]); cans %= mod;
    		cans *= fastPower(2ll, n - i); cans %= mod;

    		// cout << i << " " << cans << "\n";

    		ans += cans; ans %= mod;
    	}
    }

    // ll ans = 1ll;

    // ans *= (fastPower(2ll, mnCnt) - 1ll + mod) % mod; ans %= mod;
    // // cout << ans << "\n";
    // ans *= (fastPower(2ll, cnt) % mod) % mod; ans %= mod;
    // // cout << ans << "\n";
    // ans *= (fastPower(2ll, pcnt[mnId - 1ll])) % mod; ans %= mod;

    return (ans == 0ll? 1: ans);
}

ll slv3(vector <ll> &a, ll n){
	int mx = 0, mn = 0;
	for(auto u:a) {
	mx = max(mx+u, abs (mn+u)); mn += u;
	}
	if(mn == mx) {
	// cout<<fastPower(2,n)<<endl;
		return fastPower(2,n);
	}
	int ans = 0;
	int pre = 1;
	int next = mn;
	int sum = 0;
	for(int i=0;i<n;i++) {
	sum += a[i];
	next -= a[i];
	if(sum >= 0) pre = pre*2%mod;
	if(mx == abs (sum)+next) ans + pre*fastPower(2,n-i-1);
	}
	ans %= mod;
	// cout<<ans<<endl;
	return ans;
}

// aabaaba

ll slv1(ll i, ll val, vector <ll> &a, ll n, ll mx){
	if(i == n){
		return (val == mx);
	}

	ll a1 = slv1(i + 1, val + a[i], a, n, mx);
	ll a2 = slv1(i + 1, abs(val + a[i]), a, n, mx);

	return a1 + a2;
}

void matcher(){

	vector <ll> tmp = {0, 0, 0, 0, 0};

	rep(i, -1, 3){
		rep(j, -1, 3){
			rep(k, -1, 3){
				rep(l, -1, 3){
					rep(m, -1, 3){
						tmp = {i, j, k, l, m};

						ll mx = getMx(tmp, 5);

						ll a1 = slv1(0, 0, tmp, 5, mx);
						ll a2 = slv3(tmp, 5);

						if(a1 != a2){
							print(tmp, xyz, 5);
							cout << mx << " " << a1 << " " << a2 << "\n";
							cout << "Mismatch\n";
						}
						else{
							// cout << "Match\n";
						}
					}
				}
			}
		}
	}
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);    

    ll ans = slv2(a, n);
    cout << ans << "\n";
}

int main(){
    
    fast();

    matcher();
    cout << "Done\n";

    // for(ll i = 1ll; i < mxn; ++i){
    // 	factorial[i] = factorial[i - 1ll] * i;
    // 	factorial[i] %= mod;
    // }

    // ll t;
    // cin >> t;

    // while(t--){
    //     solve();
    // }

    return 0ll;
}