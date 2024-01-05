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
multiset <int> getSquareDigits(int x){

	multiset <int> mst;

	x *= x;

	while(x){
		mst.insert(x % 10);
		x /= 10;
	}

	return mst;
}

void solve() {
    int n;
    cin >> n;

    if(n == 1){
    	cout << 1 << "\n";
    }
    else{
    	int spc = (n - 3) / 2;

    	vector <string> ans;


    	for(int i = 0; i <= spc; ++i){
    		string tmp;
    		tmp += "1";

    		for(int j = 0; j < i; ++j){
    			tmp += "0";
    		}

    		tmp += "6";

    		for(int j = 0; j < i; ++j){
    			tmp += "0";
    		}

    		tmp += "9";

    		while(tmp.size() != n){
    			tmp += "0";
    		}

    		ans.pb(tmp);
    	}

    	for(int i = 0; i <= spc; ++i){
    		string tmp;
    		tmp += "9";

    		for(int j = 0; j < i; ++j){
    			tmp += "0";
    		}

    		tmp += "6";

    		for(int j = 0; j < i; ++j){
    			tmp += "0";
    		}

    		tmp += "1";

    		while(tmp.size() != n){
    			tmp += "0";
    		}

    		ans.pb(tmp);
    	}

    	string tmp = "196";

    	while(tmp.size() != n){
    		tmp += "0";
    	}

    	ans.pb(tmp);

    	for(auto it : ans){
    		cout << it << "\n";
    	}
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