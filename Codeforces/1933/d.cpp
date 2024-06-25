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

    int oneCnt = 0;
    int mn = a[0];

    for(auto it : a){
    	oneCnt += (it == 1);
    	mn = min(mn, it);
    }

    if(oneCnt > 1){
    	cout << "NO\n";
    }
    else if(oneCnt == 1){
    	cout << "YES\n";
    }
    else{
    		
    	sort(a.begin(), a.end());
    	if(a[0] != a[1]){
    		cout << "YES\n";
    	}
    	else{
    		bool ok = 0;
    		for(auto it : a){
    			if(it % mn > 0){
    				ok = 1;
    				break;
    			}
    		}

    		if(ok) cout << "YES\n";
    		else cout << "NO\n";
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