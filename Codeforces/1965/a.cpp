#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

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
 	int n, k;
 	cin >> n >> k;

 	vector <int> a(n);
 	read(a, i, n);

 	sort(a.begin(), a.end());

 	map <int, int> cnt;

 	vector <int> xyz;

 	for(auto it : a){
 		cnt[it]++;
 	}   

 	for(auto it : cnt){
 		xyz.pb(it.ss);
 	}

 	sort(xyz.begin(), xyz.end());

 	// print(xyz, i, xyz.size());
 	int till = 0;
 	for(int i = xyz.size() - 1; i >= 0; --i){
 		if(xyz[i] >= k){
 			if(i - 1 >= 0) xyz[i - 1] += (k - 1);
 		}
 		else{
 			till = i;
 			break;
 		}
 	}

 	if(xyz[0] >= k){
 		xyz[0] = k - 1;
 	}

 	int ans = 0;
 	rep(i, 0, till + 1){
 		ans += xyz[i];
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