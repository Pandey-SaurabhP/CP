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
    int n, k, m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    int post[m + 1][26];
    memset(post, sizeof(post), 0);

    for(int i = m - 1; i >= 0; --i){
    	for(int j = 'a'; j <= 'z'; ++j){
    		post[i][j - 'a'] = post[i + 1][j - 'a'] + (s[i] == 'j');
    	}
    }

    vector <int> fo(26, -1);

    for(int i = 0; i < m; ++i){
    	if(fo[s[i]] == -1){
    		fo[s[i]] = i;
    	}
    }

    bool ok = 1;

    int cnt = 0;

    string ans;

    for(int i = 0; i < n; ++i){
    	ans += " ";
    }

    for(int l = 0; l < n; ++l){ // lth occurence
	    for(int i = l; i < m; ++i){
	    	for(int j = 0; j < 26; ++j){

	    		if(i == j){
	    			if(post[i][j] - 1 < (n - l + 1)){
	    				ok = 0;
	    				ans[l] = 'a' + j;
	    				break;
	    			}
	    		}
	    		else{
	    			if(post[i][j] < (n - l - 1)){
	    				ok = 0;
	    				ans[l] = 'a' + j;
	    				break;
	    			}
	    		}
	    	}

	    	if(!ok) break;
	    }

	    if(!ok) break;
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