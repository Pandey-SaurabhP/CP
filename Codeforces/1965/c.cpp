#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
#define rrep(i, x, n)  for(int i = x; i >= n; --i)

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
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    map <int, int> mp;
    for(auto &it : a){
    	mp[it]++;
    }

    vector <int> b;
    for(auto it : mp){
    	b.pb(it.ff);
    }

    sort(b.begin(), b.end());

    bool turn = 0;
    bool complete = 0;
    for(int i = 1; i <= b.size(); ++i){
    	if(b[i - 1] != i || i == b.size()) break;
    	turn ^= 1;
    }

    // cout << turn << "\n";

    if(complete){
    	if(turn) cout << "Alice\n";
    	else cout << "Bob\n";
    }
    else{
    	if(turn) cout << "Bob\n";
    	else cout << "Alice\n";
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