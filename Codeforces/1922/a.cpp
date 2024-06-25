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
	int n;
	cin >> n;

	string a, b, c;
	cin >> a >> b >> c;

	bool mismatch = 0;

	string t;

	for(int i = 0; i < n; ++i){
		if(a[i] == b[i]){
			t += a[i];
		}
		else{
			t += (c[i] - 'a' + 'A');
		}
	}    

	bool ok = 1;
	for(int i = 0; i < n; ++i){
		if(t[i] >= 'a' && t[i] <= 'z'){
			if(t[i] == c[i]){
				ok = 0;
				break;
			}
		}
		else{
			if(t[i] - 'A' + 'a' == a[i] || t[i] - 'A' + 'a' == a[i]){
				ok = 0;
				break;
			}
		}
	}

	if(ok) cout << "Yes\n";
	else{
		cout << "No\n";
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