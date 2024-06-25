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

int countMaxima(vector <int> &a, int n){
	int ans = 0;
	for(int i = 1; i < n - 1; ++i){
		if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
			++ans;
		}
	}

	return ans;
}

void solve() {
    
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    set <int> st;
    for(int i = 1; i <= n; ++i){
    	st.insert(i);
    }

    vector <int> ans1(n);
    bool makeLess = 1;
    int lst = 0;

    for(int i = 0; i < n; ++i){
    	// Largest number that will make the current < 9

    	if(makeLess){
    		auto it = st.lower_bound(n - a[i] + 1);
    		if(*it + a[i] >= n + 1){
    			if(it != st.begin()) --it;
    		}

    		st.erase(*it);
    		ans1[i] = *it;

    		if(*it != lst) makeLess ^= 1;

    		lst = *it;
    	}
    	else{
    		auto it = st.lower_bound(n - a[i] + 1);
    		ans1[i] = *it;
    		st.erase(*it);

    		if(*it != lst) makeLess ^= 1;

    		lst = *it;
    	}
    }
    int a1 = countMaxima(ans1, n);

    for(int i = 1; i <= n; ++i) st.insert(i);

    vector <int> ans2(n);
    makeLess = 1;
    lst = 0;

    for(int i = 0; i < n; ++i){
    	// Largest number that will make the current <= 9

    	if(makeLess){
    		auto it = st.lower_bound(n - a[i] + 1);
    		st.erase(*it);
    		ans2[i] = *it;

    		if(*it != lst) makeLess ^= 1;

    		lst = *it;
    	}
    	else{
    		auto it = st.lower_bound(n - a[i] + 1);
    		

    		if(*it + a[i] <= (n + 1)){
    			if(it != st.end()) ++it;
    		}

    		ans2[i] = *it;
    		st.erase(*it);

    		if(*it != lst) makeLess ^= 1;

    		lst = *it;
    	}
    }

    int a2 = countMaxima(ans2, n);

    // print(ans1, i, n);
    // print(ans2, i, n);

    if(a1 < a2){
    	ans1 = ans2;
    }

    rep(i, 0, n){
    	cout << ans1[i] << " ";
    }
    cout << "\n";

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