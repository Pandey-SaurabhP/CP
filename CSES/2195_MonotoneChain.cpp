#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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

ll getOrientation(pii a, pii b, pii c){
// ac x bc

	ll x1 = a.ff, y1 = a.ss;
	ll x2 = b.ff, y2 = b.ss;
	ll x3 = c.ff, y3 = c.ss;

// cross product
	ll v = (x3 - x2) * (y2 - y1) - (y3 - y2) * (x2 - x1);

	if(v == 0) return 0;
	if(v < 0) return -1;
	return 1;
}


void solve() {
    ll n;
    cin >> n;

    vector <pii> a(n);
    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ff >> a[i].ss;
    }

    sort(a.begin(), a.end());

    pii p1 = a[0];
    pii p2 = a[n - 1];

    vector <pii> up, down;

    for(ll i = 0; i < n; ++i){
   		while((up.size() >= 2) && (getOrientation(up[up.size() - 2], up[up.size() - 1], a[i]) == 1)){
   			up.pop_back();
   		}
    	up.pb(a[i]);
    }

    for(int i = n - 1; i >= 0; --i){
    	while((down.size() >= 2) && (getOrientation(down[down.size() - 2], down[down.size() - 1], a[i]) == 1)){
    		down.pop_back();
    	}
    	down.pb(a[i]);
    }

    set <pii> st;
	for(int i = 0; i < up.size(); ++i){
		st.insert(up[i]);
		// cout << up[i].ff << " " << up[i].ss << "\n";
	}    
	for(int i = 0; i < down.size(); ++i){
		st.insert(down[i]);
		// cout << down[i].ff << " " << down[i].ss << "\n";
	}    

	cout << st.size() << "\n";
	for(auto it : st){
		cout << it.ff << " " << it.ss << "\n";
	}
	
}

int main(){
    
    fast();

    solve();

    return 0;
}