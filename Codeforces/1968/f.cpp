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

ll lowerBound(vector <ll> &a, ll n, ll l, ll r){

    ll lo = 0;
    ll hi = n - 1;

    ll ans = -1;

    while(lo <= hi){

        ll mid = (lo + hi) / 2;
        // cout << "M: " << mid << "\n";

        if(a[mid] > r){
            hi = mid - 1;
        }
        else if(a[mid] < l){
            lo = mid + 1;
        }
        else{
            // In range
            ans = a[mid];
            hi = mid - 1;
        }
    }

    return ans;
}

ll upperBound(vector <ll> &a, ll n, ll l, ll r){
    ll lo = 0;
    ll hi = n - 1;

    ll ans = -1;

    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        // cout << mid << " ";

        if(a[mid] > r){
            hi = mid - 1;
        }
        else if(a[mid] < l){
            lo = mid + 1;
        }
        else{
            // In range
            ans = a[mid];
            lo = mid + 1;
        }
    }

    return ans;
}

void solve() {
    ll n, q;
    cin >> n >> q;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> pre(n + 1, 0);
    map <ll, vi> mp;
    rep(i, 0, n){
        pre[i + 1] = pre[i] ^ a[i]; 
        mp[pre[i + 1]].pb(i + 1);
    }


    while(q--){
        ll l, r;
        cin >> l >> r;

        // Check for complete range, ie odd number of 1s occuring
        if(pre[r] == pre[l - 1]){
            cout << "YES\n";
        }
        else{
        // Odd Size 
            int lb = upperBound(mp[pre[l - 1]], mp[pre[l - 1]].size(), l, r);
            int ub = lowerBound(mp[pre[r]], mp[pre[r]].size(), l, r);

            // cout << lb << " " << ub << "\n";

            if(lb != -1 && ub != -1 && lb > ub){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }

    cout << "\n";
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