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
#define read(a, i, n) for(int64_t i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(int64_t i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long int64_t;
typedef long double ld;
typedef pair <int64_t, int64_t> pii;

// Constants
const int64_t mxn = 1e6 + 5;
const int64_t mod = 1e9 + 7;

const int64_t mx = 5e18 + 1;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
    int64_t n, q;
    cin >> n >> q;

    int64_t id = 0;
    map <int64_t, int64_t> mp;
    vector <int64_t> vc;

    for(int64_t i = 0; i < n; ++i){
    	int64_t type, x;
    	cin >> type >> x;

    	if(type == 1){
    		if(id <= mx){
	    		mp[++id] = x;
	    		vc.pb(id);
    		}
    	}
    	else{
			if(id > mx / (x + 1)){
				id = mx;
			}
			else{
				id *= 1ll * (x + 1);
			}
		
    	}
    }
    vc.pb(++id);

    // print(vc, i, vc.size());

    while(q--){
    	int64_t id;
    	cin >> id;

    	while(id){
    		int64_t li = upper_bound(vc.begin(), vc.end(), id) - vc.begin();
    		--li;
    		// cout << li << " " << id << "\n";


    		int64_t rem = (id / vc[li]) * vc[li];
    		id -= rem;

    		if(rem == 0){
    			cout << mp[vc[li]] << " ";
    			break;
    		}

    		if(id == 0 || vc[li] + 1 == id){
    			cout << mp[vc[li]] << " ";
    			break;
    		}
    	}
    }
    cout << "\n";
}

int main(){
    
    fast();

    int64_t t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}