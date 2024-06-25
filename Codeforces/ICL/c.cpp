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

void solve() {
 	ll n, k;
 	cin >> n >> k;

 	vector <ll> a(n), c(n);
 	read(a, i, n);
 	read(c, i, n);

 	vector <ll> cnt(n + 5, 0ll);

 	vector <pii> s(n);

 	for(ll i = 0; i < n; ++i){
 		cnt[c[i]]++;
 		s[i] = {a[i], c[i]};
 	}   

 	sort(s.begin(), s.end());

 	for(int i = 0; i < n; ++i){
 		a[i] = s[i].ff;
 		c[i] = s[i].ss;
 	}

 	vector <ll> doneclr(n + 5, 0ll);

 	ll ans = INT_MAX;
 	ll done = 0;

 	ll doneTill = -1;

 	for(ll i = 0; i < n; ++i){
 		// Make each element equal to current
 		ll cur = (n - cnt[c[i]]); // Total - current color

 		// cout << "Initial : " << cur << "\n";


 		if(doneTill < i){

 			ll j = doneTill + 1;

 			while(j < n && a[j] == a[i]){
 				doneclr[c[j]]++;
	 			++done;
	 			++j;
 			}

 			doneTill = max(j - 1, doneTill);
 		}


 		ll prevLeft = done - doneclr[c[i]];

 		// cout << i << " " << doneTill << "\n";
 		// for(int i = 0; i < 6; ++i){
 		// 	cout << doneclr[i] << " ";
 		// }
 		// cout << "\n";

 		if(prevLeft > k){
 			continue;
 		}
 		else{
 			ll ck = k - prevLeft;

 			// cout << i << " -> " << cur << " " << ck << " " << prevLeft << "\n";

 			cur -= prevLeft;
 			cur -= ck;

 			ans = min(ans, max(cur, 0ll));
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