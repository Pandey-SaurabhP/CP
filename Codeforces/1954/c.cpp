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

void solve() {
	string a, b;
	cin >> a >> b;

	int n = a.size();

	bool change = 0;

	string sa, sb;

	bool larger = 0;

	for(int i = 0; i < n; ++i){
		if(!change){

			sa += a[i];
			sb += b[i];
			
			if(a[i] == b[i]){
				continue;
			}
			else{
				change = 1;

				if(a[i] < b[i]){
					larger = 1;
				}
			}

		}
		else{
			if(!larger){
				// sa is larger
				sa += min(a[i], b[i]);
				sb += max(a[i], b[i]);
			}
			else{
				// sb is larger
				sa += max(a[i], b[i]);
				sb += min(a[i], b[i]);
			}
		}
	}

	cout << sa << "\n" << sb << "\n";
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