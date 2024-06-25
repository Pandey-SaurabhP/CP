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
    int n, q;
    cin >> n >> q;

    vector <int> a(n);
    read(a, i, n);

    int sq = sqrt(n);

    int dc[sq + 1][sq + 1]; //  Blocks * Gaps // 10^2.5 + 10^2.5
    memset(dc, -1, sizeof(dc));

    for(int i = 0; i < n; ++i){
        
        for(int d = 1; d <= sq; ++d){

            int x = i / sq;
            

        }
    }


    while(q--){
        int s, d, k;
        cin >> s >> d >> k;

        if((k - s) / d <= sq){
            int sm = 0;

            int x = 1;
            for(int i = s; i <= s + d * (k - 1); s += d){
                sm += a[i] * x;
                ++x;
            }

            cout << sm << "\n";
        }
        else{

        }
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