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
typedef pair <ld, ld> pii;

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

bool isAreaZero(pii a, pii b, pii c){

    if(a.ss == b.ss && b.ss == c.ss){
        if(a.ff >= min(b.ff, c.ff) && a.ff <= max(b.ff, c.ff)){
            return 1;
        }

        return 0;
    }


    if(a.ff == b.ff && b.ff == c.ff){
        if(a.ss >= min(b.ss, c.ss) && a.ss <= max(b.ss, c.ss)){
            return 1;
        }

        return 0;
    }
    
    return 0;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector <pii> a(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i].ff >> a[i].ss;
    }
    a.pb(a[0]);

    for(ll i = 0; i < m; ++i){
        ld x, y;
        cin >> x >> y;

        // Check for each point

        ll cnt = 0; ll ymatch = 0;
        bool boundary = 0;
        
        for(ll i = 0; i < n; ++i){
            if(isAreaZero({x, y}, a[i], a[i + 1])){
                boundary = 1;
                break;
            }

            if((min(a[i].ss, a[i + 1].ss) < y) && (max(a[i].ss, a[i + 1].ss) >= y) && (x <= max(a[i].ff, a[i + 1].ff))){
                if(a[i].ss != a[i + 1].ss){
                    ld xi = 1.0 * ((y - a[i].ss) * (a[i + 1].ff - a[i].ff)) / (a[i + 1].ss - a[i].ss) + a[i].ff;
                    // cout << "xi : " << xi << "\n";
                    if((a[i].ff == a[i + 1].ff) || (a[i].ff <= xi)){
                        ++cnt;
                    }   
                }
            }
        }


        if(boundary){
            cout << "BOUNDARY\n";
        }
        else if(cnt % 2 == 0){
            cout << "OUTSIDE\n";
        }
        else{
            cout << "INSIDE\n";
        }
    }    
}

int main(){
    
    fast();

    solve();

    return 0;
}