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
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

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

    vector <int> st, ed;


    for(int i = 0; i < n; ++i){
    	int j = i;

    	while(j < n && a[j] == a[i]){
    		++j;
    	}

    	--j;

    	st.pb(i);
    	ed.pb(j);
    	i = j;
    }

    int q;
    cin >> q;

    while(q--){
    	int l, r;
    	cin >> l >> r;

    	--l, --r;

    	int ending = upper_bound(st.begin(), st.end(), r) - st.begin();
    	--ending;

    	int starting = upper_bound(st.begin(), st.end(), l) - st.begin();
    	--starting;

    	if(ending > starting){
    		cout << ed[starting] + 1 << " " << st[starting + 1] + 1 << "\n";
    	}
    	else{
    		cout << -1 << " " << -1 << "\n";
    	}

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