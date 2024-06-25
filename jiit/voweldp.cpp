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

bool isVowel(char x){
	return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

void solve() {
    
    string s;
    cin >> s;



    int k;
    cin >> k;

    int i = 0;
    int j = 0;
    int n = s.size();
    
    for(int i = 0; i < n; ++i){
    	s[i] = tolower(s[i]);
    }

    map <char, int> mp;

    int ans = 0;

    // O(n)

    while(j < n){

    	if(isVowel(s[j])){

    		++mp[s[j]];

    		if(mp[s[j]] == 1){
    			--k;
    		}

    		if(k < 0){
	    		while(i < j){
	    			if(isVowel(s[i])){
	    				--mp[s[i]];

	    				if(mp[s[i]] == 0){
	    					++k;
	    				}
	    			}

	    			++i;

	    			if(k == 0) break;
	    		}
    		}
    	}

    	if(k == 0){
    		ans = max(ans, j - i + 1);
    	}

    	++j;
    }

    cout << ans << "\n";
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