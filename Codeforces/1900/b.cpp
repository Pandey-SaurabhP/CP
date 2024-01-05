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
    int a, b, c;
    cin >> a >> b >> c;

    bool oka, okb, okc;
    oka = okb = okc = 0;

    int ta, tb, tc, x;

    ta = a, tb = b, tc = c;
    x = min(b, c);

    a += x;
    b -= x;
    c -= x;

    if(max(b, c) % 2 == 0){
    	oka = 1;
    }

    a = ta, b = tb, c = tc;
    x = min(a, c);

    a -= x;
    b += x;
    c -= x;

    if(max(a, c) % 2 == 0){
    	okb = 1;
    }

    a = ta, b = tb, c = tc;
    x = min(a, b);

    a -= x;
    b -= x;
    c += x;

    if(max(a, b) % 2 == 0){
    	okc = 1;
    }

    cout << oka << " " << okb << " " << okc << "\n";
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