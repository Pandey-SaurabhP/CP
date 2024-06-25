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


void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);


    vector <ll> pre(n + 1, 0);

    ll mn = a[0];
    ll mnId = 0;
    for(ll i = 0; i < n; ++i){
    	pre[i + 1] = pre[i] + a[i];

    	if(pre[i + 1] <= mn){
    		mn = pre[i + 1];
    		mnId = i;
    	}
    	
    }

    // Found the min val
    // cout << "mn : " << mnId << "\n";

    if(mn >= 0){
    	cout << abs(pre[n]) << "\n";
    }
    else{
    	ll ans = abs(pre[mnId + 1]);

    	for(ll i = mnId + 1; i < n; ++i){
    		ans += a[i];
    	}

    	cout << abs(ans) << "\n";
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