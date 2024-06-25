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
const ll mxn = 1e6 + 1;
const ll mod = 1e9 + 7;
const ll lgn = 1e3 + 1;
 
// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
// Solve
 
int a[mxn];
int bit[lgn];
int sqn;
 
int query(int l, int r, int n){
 
	int ans = 0;
 
	for(int i = l; i <= r;){
		if(i % sqn == 0 && i + sqn - 1 <= r){
			ans += bit[i / sqn];
			i += sqn;
		}
		else{
			ans += a[i];
			++i;
		}
	}
 
	return ans;
}
 
 
bool cmp(pair <pii, int> a, pair <pii, int> b){
	if(a.ff.ff / sqn < b.ff.ff / sqn){
		return 1;
	}
	else if(a.ff.ff / sqn > b.ff.ff / sqn){
		return 0;
	}
 
	return (a.ff.ss < b.ff.ss);
}
 
void solve() {
    	
    int n, q;
    cin >> n >> q;
 
    read(a, i, n);
 
    int lo = 1;
    int hi = n;
 
    while(lo <= hi){
    	int mid = (lo + hi) / 2;
 
    	if(mid * mid >= n){
    		sqn = mid;
    		hi = mid - 1;
    	}
    	else{
    		lo = mid + 1;
    	}
    } 
 
    for(int i = 0; i < n; ++i){
    	bit[i / sqn] += a[i];
    }
 
    vector <pair <pii, int>> vc(q);
 
    for(int i = 0; i < q; ++i){
    	int l, r;
    	cin >> l >> r;
 
    	--l, --r;
    	vc[i] = {{l, r}, i};
    }
 
    sort(vc.begin(), vc.end(), cmp);
 
    int l, r;
    l = r = -1;
 
    unordered_map <int, int> mp;
    int cnt = 0;
 
 
    vector <int> ans(q, -1);
 
    for(auto it : vc){
    	int tl = it.ff.ff;
    	int tr = it.ff.ss;
 
    	while(l > tl){
    		--l;
			mp[a[l]]++;
		}
 
    	while(r < tr){
    		++r;
    		mp[a[r]]++;
    	}
	
		while(l < tl){
			mp[a[l]]--;
			if(mp[a[l]] <= 0) mp.erase(a[l]);
			++l;
		}
		
		while(r > tr){
			mp[a[r]]--;
			if(mp[a[r]] <= 0) mp.erase(a[r]);
			--r;
		}
 
    	ans[it.ss] = mp.size();
    }
 
    for(int i = 0; i < q; ++i){
    	cout << ans[i] << "\n";
    }
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}