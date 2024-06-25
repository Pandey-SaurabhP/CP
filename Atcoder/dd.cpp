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

ll getAns(vector <ll> &a, ll n)
{
    vector <ll> left(n);
    vector <ll> right(n);
 
    left[0] = min(a[0], (ll)1);
 
    for (ll i = 1; i < n; ++i){
        left[i] = min(a[i], min(left[i - 1] + 1, (ll)i + 1));
    }
 
    right[n - 1] = min(a[n - 1], (ll)1);
 
    for (ll i = n - 2; i >= 0; --i)
        right[i] = min(a[i], min(right[i + 1] + 1, n - i));
 
    ll tot[n];
    for (ll i = 0; i < n; ++i)
        tot[i] = min(right[i], left[i]);
 
    ll max_ind = 0;
    for (ll i = 0; i < n; ++i)
        if (tot[i] > tot[max_ind])
            max_ind = i;
 
    ll cost = 0;
    ll height = tot[max_ind];
 
    return height;
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    ll ans = getAns(a, n);

    cout << ans << "\n";

}

int main(){
    
    fast();
        solve();
    

    return 0;
}