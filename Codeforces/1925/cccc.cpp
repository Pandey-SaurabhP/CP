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
    int n, k, m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    set <char> st;
    string tmp;

    for(int i = 0; i < m; ++i){
    	st.insert(s[i]);

    	if(st.size() == k){
    		tmp += char(s[i]);
    		st.clear();
    	}
    }


    if(tmp.size() >= n){
    	cout << "YES\n";
    }
    else{
    	// Answer must contain a subpart + unfound word

    	for(char i = 'a'; i < 'a' + k; ++i){
    		if(!st.count(i)){
    			tmp += char(i);
    			break;
    		}
    	}

    	while(tmp.size() != n){
    		tmp += 'a';
    	}

    	cout << "NO\n" << tmp << "\n";
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