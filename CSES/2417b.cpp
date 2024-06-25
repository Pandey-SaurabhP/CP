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
			for(ll j = i; j < mxn; j += i){
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
			nu[i] = -1;
		}
		else{
			nu[i] = 1;
		}
	}
}
 
void solve() {
    ll n;
    cin >> n;
 
    vector <ll> a(n);
    read(a, i, n);
 	
 	vector <ll> cnt(mxn, 0);
 
    for(ll i = 0; i < n; ++i){
    	++cnt[a[i]];
    }
 
    ll ans = 0;
 
    for(ll i = 2; i < mxn; ++i){

    	if(nu[i] == 0) continue;

    	ll d = 0;

    	for(ll j = i; j < mxn; j += i){


    		d += cnt[j];

			// cout << j << " : " << d << " " << ((d * (d - 1)) / 2) << "\n";
    	}

    	ans += nu[i] * ((d * (d - 1)) / 2);

		
    }
 
    ll aa = (n * (n - 1)) / 2;
    aa -= ans;
 
    cout << aa;
 
    
}
 
int main(){
    
    fast();

    fill();
 
    solve();
    return 0;
}