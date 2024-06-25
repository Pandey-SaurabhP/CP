#include <bits/stdc++.h>
using namespace std;

#define pb          push_back
#define pf          push_front

typedef long long ll;
typedef long double ld;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

ll dp[201][601][601];
ll slv(ll i, ll a, ll b, ll c, vector <vector <ll>> &ar, ll &x, ll &y){
	if(i == ar.size()){
		return (a == b && b == c? 0: INT_MAX);
	}

	if(dp[i][a][b] != -1){
		return dp[i][a][b];
	}

	ll c1 = slv(i + 1, a + ar[i][0], b + ar[i][1], c + ar[i][2], ar, x, y);
	ll c2 = slv(i + 1, a + ar[i][1], b + ar[i][2], c + ar[i][0], ar, x, y) + x;
	ll c3 = slv(i + 1, a + ar[i][2], b + ar[i][0], c + ar[i][1], ar, x, y) + x;
	ll c4 = slv(i + 1, a + ar[i][2], b + ar[i][1], c + ar[i][0], ar, x, y) + y;

	return dp[i][a][b] = min(min(c1, c2), min(c3, c4));
}

void solve() {
	memset(dp, -1, sizeof(dp));

    ll n, k;
    cin >> n >> k;

    vector <vector <ll>> ar(n);

    ll x, y;
    cin >> x >> y;

    for(ll i = 0; i < n; ++i){
    	ll a, b, c;
    	cin >> a >> b >> c;

    	vector <ll> tmp = {a, b, c};

    	ar[i] = tmp;
    }

    ll ans = slv(0, 0, 0, 0, ar, x, y);

    if(ans >= INT_MAX){
    	cout << -1 << "\n";
    }
    else{
    	cout << ans << "\n";
    }
}

int main(){
    
    fast();
    solve();

    return 0;
}