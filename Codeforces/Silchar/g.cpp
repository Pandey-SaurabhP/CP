#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
bool solve(int i, int j, int rem, string &s, int &maxRem){

	if(i >= j){
		return 1;
	}
	if(rem > maxRem){
		return 0;
	}

	bool a1 = solve()

}

bool check(string s, int sz){

}

void solve() {
    string s;
    cin >> s;

    int lo = 1;
    int hi = s.size();

    int ans = 1;
    while(lo <= hi){
    	int mid = (lo + hi) / 2;

    	if(check(s, mid)){
    		ans = mid;
    		mid = lo + 1;
    	}
    	else{
    		mid = hi - 1;
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