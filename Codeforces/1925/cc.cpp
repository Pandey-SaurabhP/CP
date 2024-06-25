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

int dp[1001][28][28];
string tmp;

bool slv(int i, char ch, int n, vector <vector <pii>> &post, string &s, int &m, int &k){
	// cout << i << ' '<< ch << " " << n << "\n";

	if(n == 0){
		return 1;
	}	

	if(dp[i][ch - 'a'][k] != -1){
		return dp[i][ch - 'a'][k];
	}

	bool ans = 1;

	for(int j = 'a'; j < 'a' + k; ++j){
		if(i + 1 < m){
			if(post[i + 1][j - 'a'].ff >= n){
				ans &= slv(post[i + 1][j - 'a'].ss, j, n - 1, post, s, m, k);

				if(!ans){
					tmp += j;
					return 0;
				}
			}
			else{
				tmp += j;
				return 0;
			}
		}
		else{
			return 0;
		}
	}

	return dp[i][ch - 'a'][k] = ans;
}

void solve() {
	tmp.clear();
    int n, k, m;
    cin >> n >> k >> m;

    for(int i = 0; i <= n; ++i){
    	for(int j = 0; j < 28; ++j){
    		for(int l = 0; l < 28; ++l){
    			dp[i][j][l] = -1;
    		}
    	}
    }

    string s;
    cin >> s;

    vector <vector <pii>> post(m + 1, vector <pii> (26, {0, -1}));

    for(int i = m - 1; i >= 0; --i){
    	for(int j = 'a'; j <= 'z'; ++j){
    		if(s[i] == j){
    			post[i][j - 'a'] = {post[i + 1][j - 'a'].ff + 1, i};
    		}
    		else{
    			post[i][j - 'a'] = post[i + 1][j - 'a']; 
    		}
    	}
    }

    // for(int i = 0; i < m; ++i){
    // 	for(int j = 0; j < k; ++j){
    // 		cout << "( " << post[i][j].ff << " " << post[i][j].ss << " )  ";
    // 	}
    // 	cout << "\n";
    // }
    // cout << "\n";

    vector <int> fo(256, -1);

    for(int i = 0; i < m; ++i){
    	if(fo[s[i]] == -1){
    		fo[s[i]] = i;
    	}
    }

    bool ans = 1;
    for(int i = 'a'; i < 'a' + k; ++i){
    	tmp.clear();
    	ans &= slv(fo[i], i, n - 1, post, s, m, k);
    }

    if(ans){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";

    	char ch = tmp[tmp.size() - 1];

    	while(tmp.size() != n){
    		tmp += ch;
    	}

    	reverse(tmp.begin(), tmp.end());
    	cout << tmp << "\n";
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