#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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
    ll n, m;
    cin >> n >> m;

    vector <ll> a(n + m + 1), b(n + m + 1);
    read(a, i, n + m + 1);
    read(b, i, n + m + 1);

    vector <char> best(n + m + 1);
    vector <char> ass(n + m + 1);
    ll pc = 0, tc = 0;

    for(ll i = 0; i < n + m + 1; ++i){
    	best[i] = (a[i] > b[i]? 'p': 't');

    	if(pc == n || tc == m){
    		if(pc == n && tc == m){
    			ass[i] = 'u';
    		}
    		else if(pc == n){
    			++tc;
    			ass[i] = 't';
    		}
    		else if(tc == m){
    			++pc;
    			ass[i] = 'p';
    		}
    	}
    	else{
    		ass[i] = best[i];

    		pc += (ass[i] == 'p');
    		tc += (ass[i] == 't');
    	}
    }


    vector <ll> tp(n + m + 1, n + m); // best t assigned p
    vector <ll> pt(n + m + 1, n + m); // best p assigne t

    ll lst = n + m;
    for(ll i = n + m; i >= 0; --i){
    	if(best[i] == 't' && ass[i] == 'p'){
    		lst = i;
    	}
    	if(ass[i] == 'u'){
    		lst = i;
    	}

    	tp[i] = lst;
    }


   	lst = n + m;
    for(ll i = n + m; i >= 0; --i){
    	if(best[i] == 'p' && ass[i] == 't'){
    		lst = i;
    	}
    	if(ass[i] == 'u'){
    		lst = i;
    	}

    	pt[i] = lst;
    }

    vector <ll> ans(n + m + 1);


    ll total = 0;
    for(ll i = 0; i < n + m + 1; ++i){
    	if(ass[i] == 't'){
    		total += b[i];
    	}
    	else if(ass[i] == 'p'){
    		total += a[i];
    	}
    }

    for(ll i = 0; i < n + m + 1; ++i){
    	if(ass[i] == 't'){
    		ll ans = total - b[i] + b[tp[i]] - a[tp[i]] + a[n + m];

    		cout << ans;
    	}
    	else if(ass[i] == 'p'){
    		ll ans = total - a[i] + a[pt[i]] - b[pt[i]] + b[n + m];
    		cout << ans;
    	}
    	else if(ass[i] == 'u'){
    		cout << total;
    	}

    	cout << " ";
    }

    cout << "\n";

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