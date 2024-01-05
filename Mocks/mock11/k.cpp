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
    int x1, y1, x2, y2, x3, y3;
    int px, py;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> px >> py;

    double m1 = 1.0 * (y2 - y1) / (x2 - x1);
    double c1 = 1.0 * (y1 - m1 * x1);

    double m2 = 1.0 * (y3 - y2) / (x3 - x2);
    double c1 = 1.0 * (y2 - m2 * x2);

    double m3 = 1.0 * (y1 - y3) / (x1 - x3);
    double c1 = 1.0 * (y3 - m3 * x3);

    if(py - ((m1 * px) + c1) < 0.000000001){
    	// OK
    	double d = 1.0 * ((x1 - x3) * (x1 - x3) + (y1 - y2) * (y1 - y3));
    	double lo = 0, hi = d;

    	while(lo < hi){
    		double mid = (lo + hi) / 2.0;

    		double t = mid / d;

    		double xt = ((1 - t) * x1 + t * x3);
    		double yt = ((1 - t) * y1 + t * y3);

    		
    	}
    }
    else if(py - ((m2 * px) + c2) < 0.000000001){
    	// OK
    }
    else if(py - ((m3 * px) + c3) < 0.000000001){
    	// OK
    }
    else{
    	cout << -1 << "\n";
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