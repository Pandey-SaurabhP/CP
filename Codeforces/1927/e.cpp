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
    int n, k;
    cin >> n >> k;

    vector <int> a(n, -1);

    int st1 = 1;
    int st2 = n;

    int i = 0;

    while(i < n){

    	if(a[i] != -1){
    		break;
    	}

    	int j = i;

    	while(j < n){
    		if(j % 2 == 0){
    			a[j] = st1;
    			++st1;
    			j += k;
    		}
    		else{
    			a[j] = st2;
    			--st2;
    			j += k;
    		}
    	}

    	++i;
    }

    print(a, i, n);
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