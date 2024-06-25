#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i <= n; ++i)
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

vector <int> getLPS(string s){

	vector <int> lps(s.size() + 1, 0);
	lps[0] = 0;

	int i = 0, j = 1; // i will 

	// seventy seven
	// -0000000012345

	while(j < s.size()){
		// cout << i << " " << j << " ";
		if(s[i] == s[j]){
			// cout << "Match\n";
			lps[j] = ++i;
			++j;
		}
		else{
			if(i != 0){
				i = lps[i - 1];
			}
			else{
				lps[j] = 0;
				++j;
			}
		}
	}

	return lps;
}


void solve() {
    string s, p;
    cin >> s >> p;

    vector <int> lps = getLPS(p);

    int i = 0, j = 0;
    int counter = 0;

    while(s.size() - i >= p.size() - j){

    	if(s[i] == p[j]){
    		++i, ++j;
    	}

    	if(j == p.size()){
    		// cout << i - j << " ";
    		++counter;
    		j = lps[j - 1];
    	}
    	else if(i < s.size() && s[i] != p[j]){
    		if(j != 0){
    			j = lps[j - 1];
    		}
    		else{
    			++i;
    		}
    	}

    }

    cout << counter;

}

int main(){
    
    fast();

    solve();

    return 0;
}