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
    read(a, i, n); sort(a.rbegin(), a.rend());

    map <int, int> mp;

    for(int i = 0; i < n; ++i){
    	mp[a[i]]++;
    }

    vector <int> b;
    b.pb(a[0]);

    set <int> st;
    for(auto it : a) st.insert(it);

    int start = a[0];
	st.erase(a[0]);

	while(start){
		// cout << "Start : " << start << "\n";
		int mx = 0;
		for(auto it : st){
			if((it & start) > mx){
				mx = it & start;
			}
		}

		vector <int> tmp;
		for(auto it : st){
			if((it & mx) == mx){
				tmp.pb(it);
			}
		}

		sort(tmp.rbegin(), tmp.rend());

		// cout << "TMP : " << mx << "   ";
		// print(tmp, i, tmp.size());

		for(auto it : tmp){
			st.erase(it);
			b.pb(it);
		}

		start = mx;
	}

	// print(b, i, b.size());
	vector <int> ans;
	for(int i = 0; i < mp[a[0]]; ++i){
		ans.pb(a[0]);
	}

	for(int i = 1; i < b.size(); ++i){
		for(int j = 0; j < mp[b[i]]; ++j){
			ans.pb(b[i]);
		}
	}

	for(int i = 1; i < ans.size(); ++i){
		ans[i] = ans[i - 1] & ans[i];
	}

	print(ans, i, ans.size());


}

int main(){
    // 
    // fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}