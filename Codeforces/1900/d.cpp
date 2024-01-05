#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

vector <ll> getFactors(ll x){

	vector <ll> ans;

	for(ll i = 1; i * i <= x; ++i){
		if(x % i == 0){
			if(i == x / i){
				ans.pb(i);
			}
			else{
				ans.pb(i);
				ans.pb(x / i);
			}
		}
	}

	sort(ans.begin(), ans.end());

	return ans;
}

vector <vector <ll>> factors(mxn);

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    sort(a.begin(), a.end());

    ll ans = 0;

    vector <ll> cnt(mxn, 0);

    for(ll i = 1; i * i <= a[0]; ++i){
    	if(a[0] % i == 0){
    		if(i == (a[0] / i)){
    			++cnt[i];
    		}
    		else{
    			++cnt[i];
    			++cnt[a[0] / i];
    		}
    	}
    }

    // prll(a, i, n);

	// cout << a[0] << " : ";
    // prll(cnt, i, 20);


    for(ll i = 1; i < n - 1; ++i){

    	vector <ll> fct = factors[a[i]];
    	// vector <ll> fct = getFactors(a[i]);
    	// cout << a[i] << " : ";
    	// prll(fct, j, fct.size());

    	reverse(fct.begin(), fct.end());

    	set <pair <ll, ll>> st;

    	for(auto it : fct){
    		if(cnt[it] > 0){
    			st.insert({it, cnt[it]});

    			ans += (cnt[it] * it) * (n - i - 1);

    			vector <ll> fct2 = factors[it];
    			// vector <ll> fct2 = getFactors(a[i]);

    			for(auto jt : fct2){
    				cnt[jt] -= cnt[it];
    			}
    		}
    	}

		// cout << a[i] << " : ";
    	// prll(cnt, i, 20);    	

    	for(auto it : st){
    		vector <ll> fct2 = factors[it.first];

			for(auto jt : fct2){
				cnt[jt] += it.second;
			}
    	}


    	for(auto it : fct){
    		cnt[it]++;
    	}

    	// cout << a[i] << " : ";
    	// prll(cnt, i, 20);
    	// cout << "Ans : " << ans << "\n";
    }

    cout << ans << "\n";

    // ll ans2 = 0;
    // for(ll i = 0; i < n; ++i){
    // 	for(ll j = i + 1; j < n - 1; ++j){
    // 		ans2 += (__gcd(a[i], a[j])) * (n - j - 1);
    		
    // 	}
    // }

    // cout << ans2 << "\n";
}

int main(){
    
    fast();

    for(int i = 1; i < mxn; ++i){
    	factors[i] = getFactors(i);
    }

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}