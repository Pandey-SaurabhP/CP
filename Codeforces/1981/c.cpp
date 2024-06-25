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
vector <int> path;

bool reachable(int x, int y, int turns){

	map <int, int> mp;
	path.clear();

	int tmp = x; int cnt = 0;
	while(tmp){
		mp[tmp] = cnt++;
		tmp /= 2;
	}

	int inity = y;

	int cturns = 0;

	while(1){
		path.pb(y);

		if(mp.count(y)){
			int total = mp[y] + cturns;

			if(total <= turns && (turns - total) % 2 == 0){
				
				// Building path
				int xyz = y;
				while(xyz != x){
					if(mp.count(2 * xyz + 1)){
						xyz = 2 * xyz + 1;
					}
					else{
						xyz = 2 * xyz;
					}

					path.pb(xyz);
				}

				reverse(path.begin(), path.end());

				while(path.size() <= turns){
					path.pb(inity * 2);
					path.pb(inity);
				}
				// Done

				return 1;
			}
		}

		if(y == 0) break;

		++cturns;
		y /= 2;
	}

	return 0;

}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    vector <int> fixed;
    for(int i = 0; i < n; ++i){
    	if(a[i] != -1){
    		fixed.pb(i);
    	}
    }

    bool ok = 1;

    int xyz = fixed.size();

    for(int i = 0; i < (xyz - 1); ++i){
    	if(reachable(a[fixed[i]], a[fixed[i + 1]], fixed[i + 1] - fixed[i])){

    		for(int j = fixed[i]; j <= fixed[i + 1]; ++j){
    			a[j] = path[j - fixed[i]];
    		}
    	}
    	else{
    		ok = 0;
    		break;
    	}
    }

    if(ok){

    	// Final Work

    	if(fixed.size() > 0){
    		for(int i = fixed[0] - 1; i >= 0; --i){
    			a[i] = (a[i + 1] % 2 == 0? a[i + 1] / 2: a[i + 1] * 2);
    		}

    		for(int i = fixed.back() + 1; i < n; ++i){
    			a[i] = (a[i - 1] % 2 == 0? a[i - 1] / 2: a[i - 1] * 2);
    		}
    	}
    	else{
    		// Here
    		a[0] = 1;
    		rep(i, 1, n){
    			if(a[i - 1] % 2 == 1){
    				a[i] = a[i - 1] * 2;
    			}
    			else{
    				a[i] = a[i - 1] / 2;
    			}
    		}
    	}

    	print(a, i, n);
    }
    else{
    	cout << "-1\n";
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