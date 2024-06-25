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
    
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    if(n == 1){
    	cout << "-1\n";
    	return;
    }
    else if(n == 2){
    	if(a[0] == a[1]){
    		cout << -1 << "\n";
    	}
    	else{
    		cout << 0 << "\n";
    	}
    	return;
    }

    vector <int> pre(n);
    pre[0] = -1;
    for(int i = 1; i < n; ++i){
    	if(a[i] == a[i - 1]){
    		pre[i] = pre[i - 1];
    	}
    	else{
    		pre[i] = i - 1;
    	}

    }

    vector <int> post(n);
    post[n - 1] = n;

    for(int i = n - 2; i >= 0; --i){
    	if(a[i] == a[i + 1]){
    		post[i] = post[i + 1];
    	}
    	else{
    		post[i] = i + 1;
    	}
    } 

    int ans = INT_MAX;

    for(int i = 1; i < n - 1; ++i){
    	if(a[i - 1] == a[i + 1] && a[i - 1] != a[i]){
    		ans = min(ans, pre[i] - pre[i - 1]);
    		ans = min(ans, post[i + 1] - post[i]);
    	}
    }

    if(ans == INT_MAX){
    	cout << -1 << "\n";
    }
    else{
    	cout << ans << "\n";
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