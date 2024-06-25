#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
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

    int cnt = 0;

    string nw;
    int dt = -1;

    for(int i = 0; i < n - 4; ++i){
    	// cout << i << " " << i + 4 << "\n";
    	if(s[i] == 'm' && s[i + 1] == 'a' && s[i + 2] == 'p' && s[i + 3] == 'i' && s[i + 4] == 'e'){
    		++cnt;
    		nw += 'm';
    		nw += 'a';
    		nw += 'i';
    		nw += 'e';
    		dt = i + 4;
    		i += 3;
    		continue;
    	}
    	nw += s[i];
    	dt = i;
    }

    for(int i = dt + 1; i < n; ++i){
    	nw += s[i];
    }

    // cout << "New : " << nw << " " << nw.size() << "\n";
    int x = nw.size();

    for(int i = 0; i < x - 2; ++i){
    	if(nw[i] == 'm' && nw[i + 1] == 'a' && nw[i + 2] == 'p'){
    		++cnt;
    	}

    	if(nw[i] == 'p' && nw[i + 1] == 'i' && nw[i + 2] == 'e'){
    		++cnt;
    	}
    }

    cout << cnt << "\n";
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