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

    map <int, int> mp1, mp2, mpx;
    for(int i = 0; i < n; ++i){
    	if(i == 0 || i == n - 1){
    		mpx[a[i]] = i;
    	}
    	else if(i % 2 == 1){
    		mp1[a[i]] = i;
    	}
    	else{
    		mp2[a[i]] = i;
    	}

    	mpx[a[i]] = i;
    }

    vector <int> ans1(n, 0);

    int mx = n;

    if(!mp1.count(1)){
	    for(auto it : mp1){
	    	ans1[it.ss] = mx--;
	    }

	    for(auto it : mpx){
	    	if(!mp1.count(it.ff)){
	    		ans1[it.ss] = mx--;
	    	}
	    }
	}
	else{
		for(auto it : mp2){
	    	ans1[it.ss] = mx--;
	    }

	    for(auto it : mpx){
	    	if(!mp2.count(it.ff)){
	    		ans1[it.ss] = mx--;
	    	}
	    }
	}

    vector <int> ans2(n, 0);

    print(ans1, i, n);




    // Assign maximum value to least number

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