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
    int r = -1;

    for(int i = 0; i < n; ++i){
    	if(x[i] < 0){
    		l = i;
    		r = i + 1;
    	}
    	else break;
    }

    int minus = 0;

    bool ok = 1;

    while(l >= 0 && r < n){

    	if(x[l] + minus >= 0 || x[r] - minus <= 0){
    		ok = 0;
    		break;
    	}

    	if(abs(x[l]) < x[r]){

    		int fired = a[l] / k;

    		if(a[l] - fired * k > 0){
    			++fired;

    			int left = a[l] - (a[l] % k);

    			--l;
    			while(l >= 0 && r < n){
    				if(abs(x[l]) < x[r]){

    					if(a[l] - left >= 0){
    						a[l] -= left;
    					}
    					else{
    						left -= a[l];
    						a[l] = 0;
    						--l;
    					}
    				}
    				else{
    					if(a[r] - left >= 0){
    						a[r] -= left;
    					}
    					else{
    						left -= a[r];
    						a[r] = 0;
    						++r;
    					}
    				}
    			}
    		}
    		else{
    			--l;
    		}

    		minus += fired;
    	}
    	else{
    		if(a[r] - fired * k > 0){
    			++fired;

    			int left = a[r] - (a[r] % k);

    			++r;
    			while(l >= 0 && r < n){
    				if(abs(x[l]) < x[r]){

    					if(a[l] - left >= 0){
    						a[l] -= left;
    					}
    					else{
    						left -= a[l];
    						a[l] = 0;
    						--l;
    					}
    				}
    				else{
    					if(a[r] - left >= 0){
    						a[r] -= left;
    					}
    					else{
    						left -= a[r];
    						a[r] = 0;
    						++r;
    					}
    				}
    			}
    		}
    		else{
    			--l;
    		}

    		minus += fired;
    	}
    }

    if(!ok){
    	cout << "NO\n";
    }
    else{

    	while(l >= 0){
    		if(x[l] - minus >= 0){
    			ok = 0;
    			break;
    		}

    		int fired = a[l] / k;

    		if(a[l] % k != 0){
    			++fired;
    		}
    		else{
    			--l;
    			continue;
    		}

    		int left = (a[r] - (a[r] % k));
    		--l;
    		while(l >= 0){

    			if(a[l] - left >= 0){
    				a[l] -= left;
    			}
    			else{

    			}
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