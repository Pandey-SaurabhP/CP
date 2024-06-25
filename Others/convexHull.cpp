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

bool okay(pii a, pii b, vector <pii> &ar, int n){
	ll x1, y1, x2, y2, x3, y3;

	x1 = a.ff, y1 = a.ss;
	x2 = b.ff, y2 = b.ss;

	int l, r;
	l = r = 0;

	for(int i = 0; i < n; ++i){

		x3 = ar[i].ff, y3 = ar[i].ss;

		ll lhs = (y2 - y1) * (x3 - x1);
	 	ll rhs = (y3 - y1) * (x2 - x1);

	 	if(lhs > rhs){
 			++r;
	 	}   
	 	else if(lhs < rhs){
	 		++l;
	 	}
	}

 	return (l == 0 || r == 0);
}


void slv(int i, int j, vector <pii> &a){

	if(j - i + 1 <= 5){
		// brute force
		
		return;
	}
	else{

		// Divide into 2

		int mid = (i + j) >> 1;

		slv(i, mid, a);
		slv(mid + 1, j, a);

		

	}

}

void solve() {
    
    int n;
    cin >> n;

    vector <pii> a(n);
    for(int i = 0; i < n; ++i){
    	ll x, y;
    	cin >> x >> y;

    	a[i] = {x, y};
    }

    set <pii> ans;

    for(int i = 0; i < n; ++i){
    	for(int j = i + 1; j < n; ++j){
    		if(okay(a[i], a[j], a, n)){
    			ans.insert(a[i]);
    			ans.insert(a[j]);
    		}
    	}
    }

    cout << ans.size() << "\n";
    for(auto it : ans){
    	cout << it.ff << " " << it.ss << "\n";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}