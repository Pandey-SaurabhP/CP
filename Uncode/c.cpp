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

int a1(vector <int> &cnt, vector <int> &a, int n, int mex){
	int i = 0;
    int j = n - 1;

    while(i < n){
    	if(a[i] > mex){
    		++i;
    		continue;
    	}

    	if(cnt[a[i]] - 1 > 0){
    		--cnt[a[i]];
    		++i;
    	}
    	else{
    		break;
    	}
    }

    while(j >= i){
    	if(a[j] > mex){
    		--j;
    	}

    	if(cnt[a[j]] - 1 > 0){
    		--cnt[a[j]];
    		--j;
    	}
    	else{
    		break;
    	}
    }

    return max(0, j - i + 1);
}

int a2(vector <int> &cnt, vector <int> &a, int n, int mex){
	int i = 0;
    int j = n - 1;

    while(j >= 0){
    	if(a[j] > mex){
    		--j;
    	}

    	if(cnt[a[j]] - 1 > 0){
    		--cnt[a[j]];
    		--j;
    	}
    	else{
    		break;
    	}
    }

    while(i <= j){
    	if(a[i] > mex){
    		++i;
    		continue;
    	}

    	if(cnt[a[i]] - 1 > 0){
    		--cnt[a[i]];
    		++i;
    	}
    	else{
    		break;
    	}
    }

    return max(0, j - i + 1);
}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    vector <int> cnt(n + 1, 0);

    for(int i = 0; i < n; ++i){
    	cnt[a[i]]++;
    }

    int mex = -1;

    for(int i = 0; i <= n; ++i){
    	if(cnt[i] == 0){
    		mex = i;
    		break;
    	}
    }

    int ans = min(a1(cnt, a, n, mex), a2(cnt, a, n, mex));
    cout << ans << "\n";

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