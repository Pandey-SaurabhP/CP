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

bool check(string s, int n, int k){

	char xyz = s[0];

	for(int i = 0; i < n / k; ++i){
		for(int j = i * k; j < (i + 1) * k; ++j){
			
			if(s[j] != xyz){
				return 0;
			}

		}

		xyz = (xyz == '0'? '1': '0');
	}

	return 1;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s; 
    cin >> s;

    if(check(s, n, k)){
    	cout << n << "\n";
    	return;
    }
    
    int index = -1;

    for(int i = 0; i < n; ++i){
    	
    	int cnt = 0;

    	int j;
    	for(j = i; (s[i] == s[j]) && (j < n); ++j){
    		++cnt;
    	}

    	if(cnt != k){
    		cnt %= k;

    		if(cnt == 0) cnt += k;

    		index = i + cnt;
    		break;
    	}

    	i = j - 1;
    }

    string nw;
    for(int i = index; i < n; ++i){
    	nw += s[i];
    }
    for(int i = index - 1; i >= 0; --i){
    	nw += s[i];
    }

    if(check(nw, n, k)){
    	cout << index << "\n";
    }
    else{
    	cout << -1 << "\n";
    }
}

int main(){
    
    fast();

    int t;
    cin >> t;

    while(t--){
    	solve();
    }

    return 0;
}