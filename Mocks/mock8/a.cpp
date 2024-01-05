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
    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n);
    read(a, i, n);

    map <ll, ll> mp;
    for(ll i = 0; i < n; ++i){
    	mp[a[i]] = i;
    }

    sort(a.begin(), a.end());

    set <int> st;

    for(auto it : a){
    	st.insert(it);
    }

    vector <ll> color(n, -1);
    
    ll c = 1;
    ll r = 0;

    while(r < n){
    	if(color[mp[a[r]]] != -1){
    		++r;
    		continue;
    	}

    	ll x = a[r];

    	while(1){

    		color[mp[x]] = c;
    		st.erase(x);

    		int tmp = x;
    		auto it = st.upper_bound(x + k);


    		if(it == st.end()) break;
    		x = *it;

    	}


    	++c;
    	++r;
    }

    cout << c - 1 << "\n";
    print(color, i, n);
}

int main(){
    
    fast();

    solve();
    

    return 0;
}