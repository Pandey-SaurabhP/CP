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

vector <ll> nu(mxn, 1);
vector <bool> isPrime(mxn, 1);
vector <ll> cntx(mxn, 0);

void fill(){
	isPrime[0] = isPrime[1] = 0;

	for(ll i = 2; i < mxn; ++i){

		if(isPrime[i]){
			for(ll j = 2 * i; j < mxn; j += i){
				if(j % (i * i) == 0){
					nu[j] = 0;
				}
				else{
					cntx[j]++;
					isPrime[j] = 0;
				}
			}
		}	
	}

	for(ll i = 2; i < mxn; ++i){
		if(nu[i] == 0) continue;
		if(cntx[i] % 2 == 0){
			nu[i] = 1;
		}
		else{
			nu[i] = 1;
		}
	}
}

void solve() {
	fill();

    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> cnt(mxn, 0);

    for(ll i = 0; i < n; ++i){
    	for(ll j = 1; j * j <= a[i]; ++j){

    		if(a[i] % j == 0){
    			if(j == (a[i] / j)){
    				++cnt[j];

    			}
    			else{
    				++cnt[j], ++cnt[a[i] / j];
    			}
    		}
    	}
    }
    ll ans = 0;

    for(ll i = 2; i < mxn; ++i){

    	if(cnt[i] == 0 || nu[i] == 0) continue;

		ll d = cnt[i];
		ll xyz = (d * (d - 1)) / 2; xyz %= mod;

		ans += xyz; ans %= mod; ans += mod; ans %= mod;

		cout << i << " : " << nu[i] << " " << d << " " << ((d * (d - 1)) / 2) << "\n";
	
    }

    ll aa = (n * (n - 1)) / 2; aa %= mod;
    aa -= ans; aa += mod; aa %= mod;

    cout << aa << " " << ans << "\n";

    
}

int main(){
    
    fast();

    solve();
    return 0;
}