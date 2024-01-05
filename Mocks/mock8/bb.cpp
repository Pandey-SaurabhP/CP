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
ll inf = 1e18;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
    ll n, m;
    cin >> n >> m;

    vector <pii> vc(n);

    for(ll i = 0; i < n; ++i){
    	ll x, y;
    	cin >> x >> y;
    	vc[i] = {x, y};
    }

    vector <ll> d;

    for(ll i = 1; i < n; ++i){
    	d.pb(vc[i].ff - vc[i - 1].ss);
    }

    vector <ll> pre;
    pre.pb(0);

    for(ll i = 0; i < d.size(); ++i){
    	pre.pb(pre[i] + d[i]);
    }

    pre.pb(inf);

    cout << "D : ";
    print(d, i, d.size());
    cout << "Pre : ";
    print(pre, i, pre.size());

    ll ans = m;

    for(ll i = 0; i < n; ++i){
    	auto cur = upper_bound(pre.begin(), pre.end(), pre[i] + m) - pre.begin();
    	--cur;

    	cout << i << " : " << vc[cur].ss - vc[i].ff << " " << m - pre[cur] + pre[i] << "\n";
    	ans = max(ans, vc[cur].ss - vc[i].ff + (m - (pre[cur] - pre[i])));
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}