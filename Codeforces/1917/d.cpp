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
    
    int n, k, d;
    cin >> n >> k >> d;

    vector <int> a(n);
    read(a, i, n);

    vector <int> b(k);
    read(b, i, k);


    bool allZero = 1;
    for(int i = 0; i < n; ++i){
        if(a[i] != 0){
            allZero = 0;
            break;
        }
    }

    if(allZero){
        cout << d / 2 << "\n";
    }
    else{
        int ans = 0;

        for(int i = 0; i < n; ++i){
            --a[i];
        }

        int right = 0;
        for(int j = 0; j < n; ++j){
            right += (j == a[j]);
        }

        ans = max(ans, right + (d - 1) / 2);


        for(int i = 0; i < max(2 * k, 2 * n); ++i){
            if(i >= d - 1) break;

            for(int j = 0; j < b[i % k]; ++j){
                a[j]++;
            }

            int right = 0;
            for(int j = 0; j < n; ++j){
                right += (j == a[j]);
            }

            ans = max(ans, right + ((d - i - 2) / 2));
        }

        cout << ans << "\n";
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