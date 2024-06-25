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

    vector <int> a(k);
    read(a, i, k);

    vector <int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; ++i){
    	dp[i] = 0;
    	for(auto it : a){
    		if(i - it >= 0){
    			if(dp[i - it] == 0){
    				dp[i] = 1;
    			}
    		}
    	}
    }

    rep(i, 1, n + 1){
    	if(dp[i] == 0){
    		cout << "L";
    	}
    	else{
    		cout << "W";
    	}
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}