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

    string s;
    cin >> s;

    // order check
    string l, d;
    for(int i = 0; i < n; ++i){
    	if(s[i] >= '0' && s[i] <= '9'){
    		l += s[i];
    	}
    	else{
    		d += s[i];
    	}
    }

    string l2, d2;
    l2 = l, d2 = d;
    sort(l2.begin(), l2.end());
    sort(d2.begin(), d2.end());

    if(l2 != l || d2 != d){
    	cout << "NO\n";
    }
    else{
    	if(l2 + d2 == s){
    		cout << "YES\n";
    	}
    	else{
    		cout << "NO\n";
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