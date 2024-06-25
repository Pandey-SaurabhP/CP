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

void solve() {
 	  int n;
 	  cin >> n;

 	  vector <int> a(n), b(n);
 	  read(a, i, n);
 	  read(b, i, n);

 	  sort(a.begin(), a.end());
 	  sort(b.begin(), b.end());

 	  int i = n - 1;
 	  int j = n - 1;

 	  int cnt = 0;

 	  while(i >= 0){
 	  	if(a[i] <= b[j]){
 	  		--i;
 	  		--j;
 	  	}
 	  	else{
 	  		++cnt;
 	  		--i;
 	  	}
 	  }

 	  cout << cnt << "\n";
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