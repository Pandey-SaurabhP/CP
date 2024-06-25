#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
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
    ll n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n), b(m);

    read(a, i, n);
    read(b, i, m);

    map <ll, ll> mp1, mp2;

    for(auto it : b){
    	mp1[it]++;
    }

    for(ll i = 0; i < m; ++i){
    	mp2[a[i]]++;
    }

    ll cnt = 0;

    for(auto it : mp1){
    	if(mp2.count(it.ff)){
    		cnt += min(it.ss, mp2[it.ff]);
    	}
    }

    ll ans = 0;
    ans += (cnt >= k);

    for(ll i = m; i < n; ++i){
    	
    	if(mp1.count(a[i])){
    		cnt -= min(mp1[a[i]], mp2[a[i]]);
    		mp2[a[i]]++;
    		cnt += min(mp1[a[i]], mp2[a[i]]);
    	}

    	if(mp1.count(a[i - m])){
    		cnt -= min(mp1[a[i - m]], mp2[a[i - m]]);
    		mp2[a[i - m]]--;
    		cnt += min(mp1[a[i - m]], mp2[a[i - m]]);
    	}

    	ans += (cnt >= k);
    }

    cout << ans << "\n";
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