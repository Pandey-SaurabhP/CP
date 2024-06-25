#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
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

ll msb(ll x){
	for(ll i = 31; i >= 0; --i){
		if(x & (1 << i)){
			return i;
		}
	}

	return -1;
}

vector <pii> mergePairs(vector <pii> a, vector <pii> b){
	if(a.size() == 0) return b;
	if(b.size() == 0) return a;

	ll i = 0;
	ll j = 0;

	vector <pii> res;

	ll s, e;
	s = e = -1;

	while(i < a.size() || j < b.size()){
		pii cur;

		if(i >= a.size()){
			cur = b[j++];
		}
		else if(j >= b.size()){
			cur = a[i++];
		}
		else{
			cur = (a[i].ff < b[j].ff? a[i++]: b[j++]);
		}

		if(cur.ff > e){
			if(e > -1){
				res.pb({s, e});
			}

			s = cur.ff;
			e = cur.ss;
		}
		else{
			e = max(cur.ss, e);
		}
	}

	if(e > -1){
		res.pb({s, e});
	}
	return res;
}

vector<pii> merge(vector<pii>& ins) {
    if (ins.empty()) return vector<pii>{};

    vector<pii> res;

    sort(ins.begin(), ins.end());

    res.pb(ins[0]);
    for (ll i = 1; i < ins.size(); i++) {
        if (res.back().ss < ins[i].ff) res.pb(ins[i]);
        else
            res.back().ss = max(res.back().ss, ins[i].ss);
    }
    return res;
}

	
void solve() {
    ll n, x;
    cin >> n >> x;

    vector <ll> a(n);
    read(a, i, n);

    vector <vector <ll>> bits(32);

    for(ll i = 0; i < 32; ++i){
    	for(ll j = 0; j < n; ++j){
    		if(a[j] & (1 << i)){
    			bits[i].pb(j);
    		}
    	}
    }


    ll ans = -1;

    vector <pii> cnf;

    for(ll i = 31; i >= 0; --i){
    	if((1 << i) > x){
    		// This has to be broken down

    		if(bits[i].size() % 2 == 1){
    			cout << -1 << "\n";
    			return;
    		}

    		for(ll j = 1; j < bits[i].size(); ++j){
    			cnf.pb({bits[i][j - 1], bits[i][j]});
    		}
    	}
    }

    cnf = merge(cnf);

    // cout << "Before :\n";
    
    // for(auto it : cnf){
    // 	cout << it.ff << " " << it.ss << "\n";
    // }

    if(x == 0){
    	ans = cnf.size();
    	for(ll i = 0; i < cnf.size(); ++i){
    		if(i == 0){
    			ans += cnf[i].ff;
    		}
    		else{
    			ans += cnf[i].ff - cnf[i - 1].ss; 
    		}

    		if(i == cnf.size() - 1){
    			ans += (n - cnf[i].ss - 1);
    		}
    	}
    	if(cnf.size() == 0){
    		ans = n;
    	}
    	cout << ans << "\n";
    	return;
    }

    for(ll i = msb(x); i >= 0; --i){
    	if((x & (1 << i)) && (bits[i].size() == 0)){
    		break;
    	}

    	if(x & (1 << i)){
    		// Break current bit. then rest of the bits wont matter
    		// or keep current bit rest of the bits matter

    		vector <pii> pairs;

    		if(bits[i].size() % 2 == 0){
    			//  pairing possible
    			for(ll j = 0; j < bits[i].size(); j += 2){
    				pairs.pb({bits[i][j], bits[i][j + 1]});
    			}
    		}
    		else{
    			//  Cant be broken
    			if(ans == -1){
    				break;
    			}

    			continue;
    		}

    		pairs = mergePairs(pairs, cnf);

    		// for(auto it : pairs){
    		// 	cout << it.ff << " " << it.ss << "\n";
    		// }

    		ll cur = pairs.size();
    		for(ll i = 0; i < pairs.size(); ++i){
    			if(i == 0){
    				cur += pairs[0].ff;
    			}
    			else{
    				cur += pairs[i].ff - pairs[i - 1].ss - 1;
    			}

    			if(i == pairs.size() - 1){
    				cur += (n - pairs[i].ss - 1);
    			}
    		}

    		ans = max(ans, cur);
    	}	
    	else{
    		// Has to be broken
    		cout << ans << "\n";
    		return;	
    	}
    }

    
    // if(ans == -1){
    // 	cout << -1 << "\n";
    // 	return;
    // }
    // cout << "After\n";
    // for(auto it : cnf){
    // 	cout << it.ff << " " << it.ss << "\n";
    // }

    ll cur = cnf.size();
	for(ll i = 0; i < cnf.size(); ++i){
		if(i == 0){
			cur += cnf[i].ff;
		}
		else{
			cur += cnf[i].ff - cnf[i - 1].ss; 
		}

		if(i == cnf.size() - 1){
			cur += (n - cnf[i].ss - 1);
		}
	}
	

	if(cnf.size() == 0){
		ll mx = a[0];
	    for(int i = 0; i < n; ++i){
	    	mx = max(a[i], mx);
	    }

	    if(msb(x) == msb(mx) && x < mx){
	    	// Hello
	    	
	    }
	    else{
	    	cur = n;
	    }
	}

	ans = max(ans, cur);

    cout << ans << "\n";
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