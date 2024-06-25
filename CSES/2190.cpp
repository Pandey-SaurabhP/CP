#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    ll v1 = (x3 - x1) * (y4 - y1) - (x4 - x1) * (y3 - y1); // p1 (p3 x p4)
    ll v2 = (x3 - x2) * (y4 - y2) - (x4 - x2) * (y3 - y2); // p2 (p3 x p4)
    ll v3 = (x3 - x1) * (y3 - y2) - (x3 - x2) * (y3 - y1); // p3 (p1 x p2)
    ll v4 = (x4 - x1) * (y4 - y2) - (x4 - x2) * (y4 - y1); // p4 (p1 x p2)

    ll o1, o2, o3, o4;
    o1 = (v1 > 0? 1: (v1 == 0? 0: 2));
    o2 = (v2 > 0? 1: (v2 == 0? 0: 2));
    o3 = (v3 > 0? 1: (v3 == 0? 0: 2));
    o4 = (v4 > 0? 1: (v4 == 0? 0: 2));
    // cout << v1 << " " << v2 << " " << v3 << " " << v4 << "\n";

    if(o1 != o2 && o3 != o4){
        cout << "YES\n";
    }
    else{

        if(v1 == 0){
            if(v1 != v2){
                return;
            }
            if(x1 >= min(x3, x4) && x1 <= max(x3, x4) && y1 >= min(y3, y4) && y1 <= max(y3, y4)){
                cout << "YES\n";
                return;
            }
        }
        if(v2 == 0){
            if(x2 >= min(x3, x4) && x2 <= max(x3, x4) && y2 >= min(y3, y4) && y2 <= max(y3, y4)){
                cout << "YES\n";
                return;
            }
        }
        if(v3 == 0){
            if(x3 >= min(x1, x2) && x3 <= max(x1, x2) && y3 >= min(y1, y2) && y3 <= max(y1, y2)){
                cout << "YES\n";
                return;
            }
        }
        if(v4 == 0){
            if(x4 >= min(x1, x2) && x4 <= max(x1, x2) && y4 >= min(y1, y2) && y4 <= max(y1, y2)){
                cout << "YES\n";
                return;
            }
        }

        cout << "NO\n";
    }
}
// 4 8 0 -10 9 0 3 8

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}