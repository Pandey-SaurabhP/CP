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
    ll n, k, pa, pb;
    cin >> n >> k >> pa >> pb;

    --pa, --pb;

    vector <ll> p(n), a(n);
    read(p, i, n);
    read(a, i, n);

    for(ll i = 0; i < n; ++i){
    	--p[i];
    }

    ll ma = a[pa] * k, mb = a[pb] * k; 
    ll ca, cb;
    ca = cb = 0;

    vector <bool> vis(n, 0);
    ll tk = k;

    while(!vis[pa] && tk){
    	// cout << pa << " : " << ca << " " << ca + a[pa] * tk << "\n";
    	ma = max(ma, ca + a[pa] * tk);
    	vis[pa] = 1;
    	ca += a[pa];
    	pa = p[pa];
    	--tk;
    }

    vector <bool> vis2(n, 0);
    tk = k;

    // cout << "\n";

    while(!vis2[pb] && tk){
    	// cout << pb << " : " << cb << " " << cb + (a[pb] * tk) << " " << a[pb] << "\n";
    	mb = max(mb, cb + a[pb] * tk);
    	vis2[pb] = 1;
    	cb += a[pb];
    	pb = p[pb];
    	--tk;
    }

    if(ma > mb){
    	cout << "Bodya\n";
    }
    else if(ma == mb){
    	cout << "Draw\n";
    }
    else{
    	cout << "Sasha\n";
    }

    // cout << ma << " " << mb << "\n";
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