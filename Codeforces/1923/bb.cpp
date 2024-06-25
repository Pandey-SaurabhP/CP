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
    int n, k;
    cin >> n >> k;

    vector <int> a(n);
    read(a, i, n);

    vector <int> x(n);
    read(x, i, n);

    int l = -1;
    int r = 0;

    for(int i = 0; i < n; ++i){
    	if(x[i] < 0){
    		l = i;
    		r = i + 1;
    	}
    }

    while(l >= 0 && r < n){

    	int x1 = abs(x[l]);
    	int x2 = x[r];

    	if(a[l] -  )

    	int fired = 0;

    	if(x1 <= x2){
    		fired = x[l] * k;

    		while(l >= 0 && r < n){

    			if(abs(x[l]) < x[r]){

    				if(a[l] - fired <= 0){
    					fired -= a[l];
    					a[l] = 0;
    				}
    				else{
    					a[l] -= fired;
    					fired = 0;
    				}

    				--l;
    			}
    			else{

    				if(a[r] - fired <= 0){
    					fired -= a[r];
    					a[r] = 0;
    				}
    				else{
    					a[r] -= fired;
    					fired = 0;
    				}

    				++r;
    			}

    			if(fired == 0) break;
    		}

    		while(l >= 0){
    			if(a[l] - fired <= 0){
					fired -= a[l];
					a[l] = 0;
				}
				else{
					a[l] -= fired;
					fired = 0;
				}

				--l;
				if(fired == 0) break;
    		}
    		while(r < n){
    			if(a[r] - fired <= 0){
					fired -= a[r];
					a[r] = 0;
				}
				else{
					a[r] -= fired;
					fired = 0;
				}

				++r;
				if(fired == 0) break;
    		}	
    	}
    	else{
    		fired = x[r] * k;

    		while(l >= 0 && r < n){

    			if(abs(x[l]) < x[r]){

    				if(a[l] - fired <= 0){
    					fired -= a[l];
    					a[l] = 0;
    				}
    				else{
    					a[l] -= fired;
    					fired = 0;
    				}

    				--l;
    			}
    			else{

    				if(a[r] - fired <= 0){
    					fired -= a[r];
    					a[r] = 0;
    				}
    				else{
    					a[r] -= fired;
    					fired = 0;
    				}

    				++r;
    			}

    			if(fired == 0) break;
    		}

    		while(l >= 0){
    			if(a[l] - fired <= 0){
					fired -= a[l];
					a[l] = 0;
				}
				else{
					a[l] -= fired;
					fired = 0;
				}

				--l;
				if(fired == 0) break;
    		}
    		while(r < n){
    			if(a[r] - fired <= 0){
					fired -= a[r];
					a[r] = 0;
				}
				else{
					a[r] -= fired;
					fired = 0;
				}

				++r;
				if(fired == 0) break;
    		}	
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