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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector <int> a(m);
    read(a, i, m);

    string c;
    cin >> c;

    for(int i = 0; i < m; ++i){
    	--a[i];
    }

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    int j = 0;

    vector <bool> done(n, 0);
    for(auto it : a){
    	if(!done[it]){
    		s[it] = c[j];
    		++j;
    		done[it] = 1;
    	}
    }

    cout << s << "\n";
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