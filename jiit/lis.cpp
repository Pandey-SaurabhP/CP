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
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    vector <int> dp(n, 1);

    for(int i = 1; i < n; ++i){
    	for(int j = 0; j < i; ++j){
    		if(a[j] < a[i]){
    			dp[i] = max(dp[i], dp[j] + 1);
    		}
    	}
    }

    int mxId = 0;
    for(int i = 0; i < n; ++i){
    	if(dp[i] > dp[mxId]){
    		mxId = i;
    	}
    }

    vector <int> ans;
    int lstId = mxId;
    ans.pb(a[mxId]);

    while(mxId >= 0){

    	if(a[mxId] < a[lstId] && dp[mxId] == dp[lstId] - 1){
    		ans.pb(a[mxId]);
    		lstId = mxId;
    	}

    	--mxId;
    }

        reverse(ans.begin(), ans.end());


    print(dp, i, n);
    print(ans, i, ans.size());
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