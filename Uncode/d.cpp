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

ll fastPower(ll b, ll e){

	ll ans = 1ll;

	while(e){
		if(e & 1){
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

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    map <ll, ll> cnt;

    bool ok = 1;
    ll mx = a[0];

    for(auto it : a){
    	cnt[it]++;

    	mx = max(mx, it);

    	if(cnt[it] > 2){
    		ok = 0;
    		break;
    	}
    }

    if(cnt[mx] > 1){
    	ok = 0;
    }

    if(!ok){
    	cout << "0\n";
    	return;
    }

    ll mm = 0;

    for(auto it : cnt){
    	if(it.ss == 1){
    		++mm;
    	}
    }

    --mm;

    cout << fastPower(2ll, mm) << "\n";
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