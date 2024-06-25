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
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    vector <int> aa, bb;

    aa.pb(a[0]);
    bb.pb(INT_MAX);

    for(int i = 1; i < n; ++i){
        if(a[i] <= aa[aa.size() - 1] && a[i] <= bb[bb.size() - 1]){
            if(aa[aa.size() - 1] < bb[bb.size() - 1]){
                aa.pb(a[i]);
            }
            else{
                bb.pb(a[i]);
            }
        }
        else if(a[i] <= aa[aa.size() - 1]){
            aa.pb(a[i]);
        }
        else if(a[i] <= bb[bb.size() - 1]){
            bb.pb(a[i]);
        }
        else{
            if(aa[aa.size() - 1] > bb[bb.size() - 1]){
                aa.pb(a[i]);
            }
            else{
                bb.pb(a[i]);
            }
        }
    }

    int cnt = 0;

    for(int i = 0; i < max(int(aa.size() - 1), 0); ++i){
        cnt += (aa[i] < aa[i + 1]);
    }

    for(int i = 1; i < max(int(bb.size() - 1), 1); ++i){
        cnt += (bb[i] < bb[i + 1]);
    }

    cout << cnt << "\n";
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