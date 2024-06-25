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

int secondMax(int a, int b, int c){
	vector <int> v = {a, b, c};
	sort(v.begin(), v.end());
	return v[1];
}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    int mx = min(a[0], a[1]);
    for(int i = 1; i < n; ++i){
    	mx = min(a[i], a[i - 1]);
    }

    for(int i = 2; i < n; ++i){
    	mx = max(secondMax(a[i - 2], a[i - 1], a[i]), mx);
    }

    cout << mx << "\n";
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