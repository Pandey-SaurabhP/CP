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

void solve() {
    ll n;
    cin >> n;

    vector <pii> a(n);

    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ff;
    }

    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ss;
    	--a[i].ss;
    }


    vector <int> id(n + 1, -1);
    for(int i = 0; i < n; ++i){
    	
    }
    
    sort(a.begin(), a.end());


    // for(ll i = 0; i < n; ++i){
    // 	cout << a[i].ff << " ";
    // }
    // cout << "\n";

    ll i = 0;
    ll j = n - 1;

    ll picked = 0;
    ll mn = a[n - 1].ff;

    ll gans = a[n - 1].ff;
    ll gans2 = 1;

    while(i < n){
    	if(i - 1 >= 0){
    		a[a[i - 1].ss].ff = 0;

    		if(a[i - 1].ss > j){
    			--picked;
    		}
    	}

    	while(j >= 0 && picked < i + 1){

    		if(a[j].ff == 0){
    			--j;
    			--picked;
    			continue;
    		}
    		else{

    			mn = min(a[j].ff, mn);
    			--j;
    			++picked;
    		}
    	}


    	for(ll i = 0; i < n; ++i){
	    	cout << a[i].ff << " ";
	    }
	    cout << "\n";

    	if(picked == i + 1){
    		cout << (i + 1) << " " << mn << " : " << (i + 1) * mn << "\n";
    		if((i + 1) * mn > gans){
    			gans = (i + 1) * mn;
    			gans2 = (i + 1);
    		}
    	}

    	++i;
    }

    cout << gans << " " << gans2 << "\n";
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