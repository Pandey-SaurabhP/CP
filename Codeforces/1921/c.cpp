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
    ll n, f, a, b;
    cin >> n >> f >> a >> b;

    vector <ll> ar(n);
    read(ar, i, n);

    bool ok = 1;
    ll time = 0;

    for(ll i = 0; i < n; ++i){
    	ll timeLoss = min(b, (ar[i] - time) * a);
    	time = ar[i];

    	f -= timeLoss;

    	if(f <= 0){
    		ok = 0;
    		break;
    	}
    }

    if(ok){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
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