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
 
ll sum[mxn];
ll pre[mxn];
ll post[mxn];
ll ans[mxn];
 
vector <ll> a(mxn);
 
void update(ll tl, ll tr, ll v, ll k, ll u){
    if(tl == tr){
        sum[v] = u;
        pre[v] = u;
        post[v] = u;
        ans[v] = u;
        return;
    }
 
    ll mid = (tl + tr) / 2;
 
    if(k <= mid){
        update(tl, mid, 2 * v + 1, k, u);
    }
    else{
        update(mid + 1, tr, 2 * v + 2, k, u);
    }
 
    sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
    pre[v] = max(pre[2 * v + 1], sum[2 * v + 1] + pre[2 * v + 2]);
    post[v] = max(post[2 * v + 2], post[2 * v + 1] + sum[2 * v + 2]);
    ans[v] = max(post[2 * v + 1] + pre[2 * v + 2], max(ans[2 * v + 1], ans[2 * v + 2]));
}
 
void solve() {
 
    memset(sum, 0, sizeof(sum));
    memset(pre, 0, sizeof(pre));
    memset(post, 0, sizeof(post));
 
    ll n, q;
    cin >> n >> q;
 
    read(a, i, n);
 
    for(ll i = 0; i < n; ++i){
        update(0, n - 1, 0, i, a[i]);
    }
 
    while(q--){
        ll k, x;
        cin >> k >> x;
 
        --k;
        
        update(0, n - 1, 0, k, x);
 
        cout << max(ans[0], 0ll) << "\n";
    }
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}