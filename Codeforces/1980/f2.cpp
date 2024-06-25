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
    ll n, m, k;
    cin >> n >> m >> k;

    vector <pii> a(k);

    map <pii, ll> id;

    rep(i, 0, k){
    	cin >> a[i].ff >> a[i].ss;
    	id[a[i]] = i;
    }

    // 2d binary search

    sort(a.begin(), a.end());

    vector <pii> b = a;

    ll mn = b[k - 1].ss;
    for(ll i = k - 1; i >= 0; --i){
    	b[i].ss = min(b[i].ss, mn);
    	mn = min(mn, b[i].ss);
    }

    ll init = 0;
    ll start = 0;

    for(ll i = 0; i < k; ++i){
		init += (b[i].ss - 1) * (b[i].ff - start);
		start = b[i].ff;
    }

    init += m * (n - start);

    map <ll, set <ll>> mp;


    rep(i, 0, k){
    	mp[a[i].ss].insert(a[i].ff);
    }

    ll mnRow = 0;

    vector <ll> ans(k, 0);

    for(auto it : mp){
    	ll lst = *it.ss.rbegin();
    	if(lst <= mnRow) continue;
    	ans[id[{lst, it.ff}]] = 1;

    	mnRow = lst;
    }



    cout << init << "\n";
    print(ans, i, k);
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