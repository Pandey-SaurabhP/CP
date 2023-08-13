#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 5005;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <vector <ll>> adj(mxn);
vector <ll> ans(mxn);

ll solve(ll i, ll sm, vector <ll> &v, vector <vector <ll>> &dp, ll &total){
    
    if(i == v.size()){
        return sm * (total - sm);
    }

    if(dp[i][sm] != -1) return dp[i][sm];

    ll a1 = solve(i + 1, sm, v, dp, total);
    ll a2 = solve(i + 1, sm + v[i], v, dp, total);

    return dp[i][sm] = max(a1, a2);
}

ll ss(vector <ll> &v){
    ll n = v.size();
    ll sm = accumulate(v.begin(), v.end(), 0);

    vector <vector <ll>> dp(n + 1, vector <ll> (sm + 10, -1));

    return solve(0, 0, v, dp, sm);
}

ll dfs(ll root, ll par){

    vector <ll> v;
    ll cnt = 0;

    for(auto it : adj[root]){
        
        if(it != par){
            ll tmp = dfs(it, root);

            v.push_back(tmp);
            cnt += tmp;
        }
    }

    ans[root] = ss(v);

    return 1 + cnt;
}

int main(){

    // fast();

    ll n;
    cin >> n;

    vector <ll> a(n - 1);
    read(a, n - 1);

    for(ll i = 0; i < n - 1; ++i){
        --a[i];

        adj[a[i]].push_back(i + 1);
    }

    dfs(0, 0);  
    ll sm = accumulate(ans.begin(), ans.end(), 0);

    cout << sm;
    
    return 0;
}