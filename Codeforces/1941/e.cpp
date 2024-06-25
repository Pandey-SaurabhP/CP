#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i <= n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

// Read and Prll
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

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

ll a[101][100001];

void prllpq(priority_queue <pii, vector <pii>, greater <pii>> pq){

	while(!pq.empty()){
		pii xyz = pq.top();

		cout << xyz.ff << " " << xyz.ss << "\n";
		pq.pop();
	}
	cout << "\n";
}

ll getSum(ll x, ll d, ll m){

	++d;

	ll dp[m + 1];
	dp[0] = 1;

	priority_queue <pii, vector <pii>, greater <pii>> pq;

	pq.push({1, 0});

	pii xyz;

	for(ll i = 1; i < m; ++i){
		xyz = pq.top();

		// cout << xyz.ff << " " << xyz.ss << "\n";
		// prllpq(pq);

		while(!pq.empty() && xyz.ss < (i - d)){
			pq.pop();
			xyz = pq.top();
		}

		dp[i] = xyz.ff + a[x][i] + 1;
		pq.push({dp[i], i});
	}

	return dp[m - 1];
}

void solve() {
    ll n, m, k, d;
    cin >> n >> m >> k >> d;


    for(ll i = 0; i < n; ++i){
    	read(a[i], j, m);
    }

    vector <ll> sm(n);
   	for(ll i = 0; i < n; ++i){
   		sm[i] = getSum(i, d, m);
   	}

   	vector <ll> pre(n + 1);
   	pre[0] = 0;

   	for(ll i = 1; i <= n; ++i){
   		pre[i] = pre[i - 1] + sm[i - 1];
   	}

   	ll ans = 100000000000000000ll;

   	for(ll i = k; i <= n; ++i){
   		ans = min(ans, pre[i] - pre[i - k]);
   	}

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