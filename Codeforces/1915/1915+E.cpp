#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    vector <ll> pre1(n + 1, 0);
    vector <ll> pre2(n + 1, 0);

    for(ll i = 0; i < n; ++i){
    	pre1[i + 1] = pre1[i] + (i % 2 == 0? a[i]: 0); 
    	pre2[i + 1] = pre2[i] + (i % 2 == 1? a[i]: 0);
    }

    for(ll i = 0; i < n + 1; ++i){
    	pre1[i] -= pre2[i];
    }

    map <ll, ll> mp;

    bool ok = 0;

    // prll(pre1, i, n + 1);

    for(auto it : pre1){
    	if(mp.count(it)){
    		ok = 1;
    		break;
    	}

    	mp[it] = 1;
    }

    if(ok){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
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