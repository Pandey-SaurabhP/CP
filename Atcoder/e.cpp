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

void solve() {
    int n;
    cin >> n;

    vector <int> s(n + 1);

    for(int k = 0; k <= n; ++k){
    	if(k < 1){
    		s[k] = 0;
    	}
    	else{
    		if(k % 10 == 0){
    			s[k] = s[k / 10];
    		}
    		else{
    			s[k] = s[k - 1] + 1;
    		}
    	}
    }

    print(s, i, n + 1);

    int ans = 0;
    int j = n;
    // for(int j = 1; j <= n; ++j){
    // 	ans = 0;
	    for(int k = 1; k <= j; ++k){
	    	if(k % s[k] == 0){
	    		cout << k << " " << s[k] << "\n";
	    		++ans;
	    	}
	    }

	    cout << j << " : " << ans << "\n";
	// }

    cout << ans << "\n";
}

int main(){
    
    fast();
        solve();
    

    return 0;
}