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

    string ans;

    for(int i = 1; i <= n; ++i){
    	if(i % 3 == 0){
    		ans += 'x';
    	}
    	else{
    		ans += 'o';
    	}
    }

    cout << ans << "\n";
}

int main(){
    
    solve();

    return 0;
}

// a1 a2 a3 a4
// b1 b2 b3 b4

// [a1, a1, a1, a1  [b1
//  a2, a2, a2, a2   b2
//  a3, a3, a3, a3   b3
//  a4, a4, a4, a4]  b4]


// a1b1 + a1b2 + a1b3 + a1b4 +
// a2b1 + a2b2 + a2b3 + a2b4 +
// a3b1 + a3b2 + a3b3 + a3b4 +
// a4b1 + a4b2 + a4b3 + a4b4