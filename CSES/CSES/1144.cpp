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
const ll mxn = 1e7 + 1;
const ll mod = 1e9 + 7;
 
// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
// Solve
 
int cnt[mxn];
int segTree[5 * mxn];
map <int, int> mp;
 
void build(int tl, int tr, int v){
 
	if(tl == tr){
		segTree[v] = cnt[tl];
		return;
	}
 
	int mid = (tl + tr) / 2;
 
	build(tl, mid, 2 * v + 1);
	build(mid + 1, tr, 2 * v + 2);
 
	segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}
 
void update(int tl, int tr, int v, int k, int x){
 
	if(tl == tr){
		segTree[v] = x;
		return;
	}
 
	int mid = (tl + tr) / 2;
 
	if(k >= mid){
		update(tl, mid, 2 * v + 1, k, x);
	}
	else{
		update(mid + 1, tr, 2 * v + 2, k, x);
	}
 
	segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}
 
int query(int tl, int tr, int v, int l, int r){
 
	if(tl >= l && tr <= r){
		return segTree[v];
	}	
 
	if(tl > r || tr < l){
		return 0;
	}
 
	int mid = (tl + tr) / 2;
 
	int q1 = query(tl, mid, 2 * v + 1, l, r);
	int q2 = query(mid + 1, tr, 2 * v + 2, l, r);
 
	return q1 + q2;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector <int> a(n);
    read(a, i, n);


    for(int i = 0; i < n; ++i){
    	--a[i];
    }
 
    for(auto it : a){
    	mp[it]++;
    	cnt[it / 100]++;
    }
 
    build(0, mxn - 1, 0);
 
    while(q--){
    	char ch;
    	cin >> ch;
 
    	if(ch == '?'){
    		int l, r;
    		cin >> l >> r;
 			
 			--l, --r;

    		int q1 = query(0, mxn - 1, 0, (l / 100) + 1, (r / 100) - 1);
 
    		int mxl = ((l / 100) + 1) * 100;
 
		    auto it = mp.lower_bound(l);
		    while(it != mp.end() && it->first <= min(r, mxl)){
		        q1 += it->second;
		        it++;
		    }
 
    		if((l / 100) != (r / 100)){
    			int mnr = (r / 100) * 100;
 				
	    		auto it = mp.lower_bound(max(mnr, l));
			    while(it != mp.end() && it->first <= r){
			        q1 += it->second;
			        it++;
			    }
    		}

    		cout << q1 << "\n";
    	}
    	else{
    		int k, x;
    		cin >> k >> x;
 
    		--k;
    		--x;
 
    		cnt[a[k] / 100]--;
    		update(0, mxn - 1, 0, (a[k] / 100), cnt[a[k] / 100]);
 
    		mp[a[k]]--;
    		a[k] = x;
    		mp[a[k]]++;
 
    		cnt[a[k] / 100]++;
    		update(0, mxn - 1, 0, (a[k] / 100), cnt[a[k] / 100]);
    	}
    }
}
 
int main(){
    
    // fast();
 
    solve();
 
    return 0;
   }
