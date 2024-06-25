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

    vi a(n + 1);
    rep(i, 1, n + 1){
    	cin >> a[i];
    }

    int lo = 1;
    int hi = n + 1;

    vi id(n + 1, -1);
    int targetId = -1;
    rep(i, 1, n + 1){
    	id[a[i]] = i;
    	if(a[i] == k){
    		targetId = i;
    	}
    }

    vector <pii> swaps;
    set <int> st;

    while(hi - lo > 1){
    	int mid = (lo + hi + 1) / 2;
    	// cout << mid << " : " << a[mid] << "\n";

    	if(a[mid] > k){
    		if(targetId >= mid){
    			// Requires a swap
    			// Select appropriate element and swap
    			for(int j = 1; j <= n; ++j){
    				if(!st.count(j)){
    					swaps.pb({mid, id[j]});
    					swap(a[mid], a[id[j]]);
    					break;
    				}
    			}

    			st.insert(a[mid]);
    			lo = mid;
    			continue;
    		}

    		hi = mid;
    	}
    	else{
    		if(targetId < mid){
    			// Requires a swap
    			for(int j = n; j >= 1; --j){
    				if(!st.count(j)){
    					swaps.pb({mid, id[j]});
    					swap(a[mid], a[id[j]]);
    					break;
    				}
    			}

    			st.insert(a[mid]);
    			hi = mid;
    			continue;
    		}

    		lo = mid;
    	}

    	st.insert(a[mid]);
    }

    lo = 1;
    hi = n + 1;

    while(hi - lo > 1){
    	int mid = (lo + hi + 1) / 2;

    	if(a[mid] > k){
    		hi = mid;
    	}
    	else{
    		lo = mid;
    	}

    }

    cout << "Lo : " << a[lo] << "\n";

    // rep(i, 1, n + 1){
    // 	cout << a[i] << " ";
    // }
    // cout << "\n";

    cout << swaps.size() << "\n";
    rep(i, 0, swaps.size()){
    	cout << swaps[i].ff << " " << swaps[i].ss << "\n";
    }
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