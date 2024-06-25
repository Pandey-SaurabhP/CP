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
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool ok(vector <ll> a, ll x, ll k){
	ll n = a.size();

	ll cnt = 0;
	priority_queue <pair <int, bool>, vector <pair <int, bool>>, greater <pair <int, bool>>> pq;

	for(ll i = 0; i < n; ++i){
		if(a[i] % k == 0){
			if(a[i] >= x){
				while(a[i] % k == 0){
					if(a[i] / k >= x){
						++cnt;
						a[i] /= k;
					}
					else break;
				}

				ll tmp = a[i];

				// Twist
				ll cc = 0;
				while(a[i] && a[i] % k == 0){
					++cc;
					a[i] /= k;
				}
				// Twist Ends
				a[i] = tmp;

				if(cc > 1){
					pq.push({cc, 0});
				}
			}
			else{
				while(a[i] % k == 0){
					a[i] /= k;
					++cnt;
				}
			}
		}
	}

	for(ll i = n - 1; i >= 0; --i){
		if(a[i] % k != 0 && a[i] < x){
			if(cnt > 0 && (a[i] * k) >= x){
				--cnt;
				a[i] *= k;
			}
		}
	}

	ll gr = 0;
	for(ll i = 0; i < n; ++i){
		if(a[i] >= x){
			++gr;
		}
	}

	ll ans = gr;

// Start deleting from extra
	for(ll i = n - 1; i >= 0; --i){
		if((a[i] % k != 0) && (a[i] < x) && (a[i] * k >= x)){
			if(!pq.empty()){	
				pair <int, bool> tp = pq.top();
				pq.pop();

				if(tp.ss == 0){
					a[i] *= k;

					tp.ff--;
					tp.ss = 1;
				}
				else{
					a[i] *= k;
					++gr;

					tp.ff--;
				}

				if(tp.ff > 0){
					pq.push({tp.ff, 1});
				}
			}
		}
	}

	return max(gr, ans) >= x;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, i, n);

    sort(a.begin(), a.end());

    ll lo = 1;
    ll hi = INT_MAX;
    ll ans = 1;

    while(lo <= hi){
    	ll mid = (lo + hi) / 2;

    	if(ok(a, mid, k)){
    		ans = mid;
    		lo = mid + 1;
    	}
    	else{
    		hi = mid - 1;
    	}
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