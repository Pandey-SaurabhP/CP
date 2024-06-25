#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
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
const ll mxn = 3e5 + 7;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <int> mp(mxn, 0);

int check(vector <int> &a, int k, int n){

	for(int i = 0; i <= n + 4; ++i){
		mp[i] = 0;
	}

	set <int> st;

	for(int i = 0; i <= n + 4; ++i){
		st.insert(i);
	}

	for(int i = 0; i < k; ++i){
		++mp[a[i]];

		if(mp[a[i]] > 0 && st.count(a[i])){
			st.erase(a[i]);
		}
	}

	int mex = *(st.begin());

	for(int i = k; i < n; ++i){
		++mp[a[i]];
		--mp[a[i - k]];

		if(mp[a[i - k]] == 0){
			st.insert(a[i - k]);
		}

		if(mp[a[i]] > 0){
			st.erase(a[i]);
		}

		mex = max(mex, *(st.begin()));
	}

	return mex;
}

int getMex(vector<int> &a, int n){
 	set <int> st;

 	for(int i = 0; i <= n + 4; ++i){
 		st.insert(i);
 	}

 	for(int i = 0; i < n; ++i){
 		if(st.count(a[i])) st.erase(a[i]);
 	}

 	return *(st.begin());
}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    int mex = getMex(a, n);

    int lo = 1;
    int hi = n;

    int ans = n;

    while(lo <= hi){
    	int mid = (lo + hi) / 2;

    	if(check(a, mid, n) == mex){
    		ans = min(mid, ans);
    		hi = mid - 1;
    	}
    	else{
    		lo = mid + 1;
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