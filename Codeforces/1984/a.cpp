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

bool allSame(vector <int> &a){

	for(auto it : a){
		if(it != a[0]) return 0;
	}

	return 1;
}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    if(allSame(a)){
    	cout << "NO\n";
    }
    else{
    	cout << "YES\n";

    	vector <char> ans(n, 0);

    	bool fnd = 0;
    	
    	for(int i = 0; i < n; ++i){
    		for(int j = i + 1; j < n; ++j){
    			if(a[i] == a[j]){
    				ans[i] = 1;
    				fnd = 1;
    				break;
    			}
    		}

    		if(fnd) break;
    	}

    	if(!fnd){
    		ans[0] = 1;
    	}

    	for(auto it : ans){
    		if(it == 0){
    			cout << "R";
    		}
    		else{
    			cout << "B";
    		}
    	}

    	cout << "\n";
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