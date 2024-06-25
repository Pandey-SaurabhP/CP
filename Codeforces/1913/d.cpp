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
set <vector <int>> st;

void gen(vector <int> a){

	if(st.count(a)){
		return;
	}

	st.insert(a);
	// print(a, i, a.size());

	for(int i = 0; i < a.size(); ++i){
		for(int j = i + 1; j < a.size(); ++j){
			// Selected Start and finish

			vector <int> tmp;

			for(int k = 0; k < i; ++k){
				tmp.pb(a[k]);
			}			

			int mn = a[i];
			for(int k = i; k <= j; ++k){
				mn = min(mn, a[k]);
			}

			tmp.pb(mn);

			for(int k = j + 1; k < a.size(); ++k){
				tmp.pb(a[k]);
			}


			gen(tmp);
		}
	}

}

void slv(vector <int> &a, int n){
	int rem[n][n];
	memset(rem, 0, sizeof(rem));

	for(int i= 0; i < n; ++i){ // Index
		for(int j = 1; j < n; ++j){ // Distance
			if(i - j >= 0 && a[i - j] < a[i]){
				bool ok = 1;
				for(int k = i - j; k <= i; ++k){
					if(a[k] < a[i - j]){
						ok = 0;
						break;
					}
				}

				rem[j][i] = ok;
			}
			if(i + j < n && a[i + j] < a[i]){
				bool ok = 1;
				for(int k = i; k <= i + j; ++k){
					if(a[k] < a[i + j]){
						ok = 0;
						break;
					}
				}

				rem[j][i] = ok;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << rem[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	st.clear();

    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    slv(a, n);
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