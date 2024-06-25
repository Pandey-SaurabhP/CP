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

bool check(vector <string> &s){

	for(ll i = 1; i < 6; ++i){
    	for(ll j = 1; j < 6; ++j){
    		if(s[i][j] == 'B'){
    			if( s[i - 1][j - 1] == 'B' &&
    				s[i + 1][j - 1] == 'B' &&
    				s[i - 1][j + 1] == 'B' &&
    				s[i + 1][j + 1] == 'B' ){

    				return 0;
    			}
    		}
    	}
    }

    return 1;
}

void solve() {
    vector <string> s(7);
    read(s, i, 7);

    map <pii, ll> mp;

    for(ll i = 1; i < 6; ++i){
    	for(ll j = 1; j < 6; ++j){
    		if(s[i][j] == 'B'){
    			if( s[i - 1][j - 1] == 'B' &&
    				s[i + 1][j - 1] == 'B' &&
    				s[i - 1][j + 1] == 'B' &&
    				s[i + 1][j + 1] == 'B' ){

    				mp[{i - 1, j - 1}]++;
    				mp[{i - 1, j + 1}]++;
    				mp[{i + 1, j + 1}]++;
    				mp[{i + 1, j - 1}]++;
    			}
    		}
    	}
    }

    vector <pair <ll, pii>> vc(mp.size());

    for(auto it : mp){
    	vc.pb({it.second, it.first});
    }


    sort(vc.rbegin(), vc.rend());

    ll ops = 0;

    for(auto it : vc){

    	ll x = it.ss.ff;
    	ll y = it.ss.ss;

    	s[x][y] = 'W';
    	++ops;

    	if(check(s)){
    		break;
    	}
    }

    for(auto it : s){

    	cout << it << "\n";
    }

    cout << ops << "\n";
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