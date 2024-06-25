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
 
ll getArea(vector <pii> a, ll n){
	ll ans = 0;
 
	for(ll i = 0; i < n; ++i){
		ans += (a[i].ff * a[i + 1].ss) - (a[i].ss * a[i + 1].ff);
	}
 
	return abs(ans);
}
 
void solve() {
    ll n;
    cin >> n;
 
    vector <pii> a(n);
    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ff >> a[i].ss;
    }
    a.pb(a[0]);
 
    ll boundary = 0;
 
    for(ll i = 0; i < n; ++i){
 
    	ll r1 = abs(a[i + 1].ff - a[i].ff);
    	ll r2 = abs(a[i + 1].ss - a[i].ss);
 
    	if(r1 == 0 || r2 == 0){
    		if(r1 == 0){
    			boundary += abs(r2 - 1);
    		}
    		else{
    			boundary += abs(r1 - 1);
    		}
    	}
    	else{
    		boundary += __gcd(r1, r2) - 1;
    	}
    }
 
    boundary += n;
 
    ll inside = (getArea(a, n) - boundary + 2) / 2;
 
    cout << inside << " " << boundary << "\n";
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}