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
const ll mxn = 5e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
pii segTree[4 * mxn];
 
void build(ll l, ll r, ll i, vector <ll> &a, ll &n){
    if(l == r){
        segTree[i] = {a[l], l};
        return;
    }
 
    ll mid = (l + r) / 2;
 
    build(l, mid, 2 * i + 1, a, n);
    build(mid + 1, r, 2 * i + 2, a, n);
 	
 	pii a1 = segTree[2 * i + 1];
 	pii a2 = segTree[2 * i + 2];

 	if(a1.ff >= a2.ff){
 		segTree[i] = a1;
 	}
 	else{
 		segTree[i] = a2;
 	}
    // segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]); 
}
 
pair <ll, ll> query(ll l, ll r, ll i, ll lll, ll rr){
 
    if(r < lll || l > rr) return {0, -1};
 
    if(l >= lll && r <= rr){
        return segTree[i];
    }
 
    ll mid = (l + r) / 2;

    pii q1 = query(l, mid, 2 * i + 1, lll, rr);
    pii q2 = query(mid + 1, r, 2 * i + 2, lll, rr);
 
    if(q1.ff > q2.ff){
    	return q1;
    }

    return q2;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    for(ll i = 0; i < 4 * n; ++i){
    	segTree[i] = {-1, -1};
    }

    string s;
    cin >> s;

    vector <ll> pre(n + 1, 0);

    for(ll i = 1; i <= n; ++i){
    	pre[i] = pre[i - 1] + (s[i - 1] == '1') - (s[i - 1] == '0');
    }

    vector <ll> mp(mxn, -1);

    for(ll i = 1; i <= n; ++i){
    	pre[i] = abs(pre[i]);
    	mp[pre[i]] = i - 1;
    }

    build(0, n, 0, mp, n);

    // print(pre, i, n + 1);
    // print(segTree, i, 2 * n + 1);

    // for(int i = 0; i < 5; ++i){
    // 	cout << i << " : " << mp[i] << "\n";
    // }

    string ans = "";
    for(ll i = 0; i <= n; ++i) ans += '0';

    ans[0] = '1';
	ll lst = 0;

	for(ll i = 0; i < n; ++i){
		// cout << i << " : " << lst << " " << lst + k << " :: ";
		pii mnop = query(0, n, 0, lst, lst + k);
		// cout << xyz << "\n";

		ll xyz = mnop.ff;

		if(xyz != -1){

			// if(xyz < i) break;

			ans[xyz + 1] = '1';

			i = xyz;
			lst = mnop.ss;

			// cout << i << " : " << lst + k << " " << lstOcc << "\n"; 
		}	
		else{
			break;
		}
	}

	ans.pop_back();

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