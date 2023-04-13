// pSaurabh
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

ll memo[2005][2005];

ll solve(ll i, ll kk, vector <ll> &a, ll &n, ll &k){

    if(i == n || kk == k){
        return 1ll;
    }

    if(memo[i][kk] != -1){
        return memo[i][kk] % mod;
    }

    return memo[i][kk] = ((solve(i + 1, kk, a, n, k) % mod) + (a[i] * solve(i + 1, kk + 1, a, n, k) % mod) % mod) % mod;
}


int main(){

	fast();

    for(ll i = 0; i < 2005; ++i){
        for(ll j = 0; j < 2005; ++j){
            memo[i][j] = -1;
        }
    }

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    read(a, n);

    map <ll, ll> mp;

    for(ll it : a){
        if(mp.find(it) == mp.end()){
            mp[it] = 0;
        }

        mp[it]++;
    }

    vector <ll> cnt;

    for(auto it : mp){
        cnt.push_back(it.second);
    }

    ll nn = cnt.size();

    cout << solve(0, 0, cnt, nn, k) % mod;

	return 0;	
}