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
 
pii mn;
ld inf = 1000000000000000000.0;
 
ll getOriention(pii a, pii b, pii c){
	
	// Check the orientation of bc wrt ab
	ll x1 = a.ff, y1 = a.ss;
	ll x2 = b.ff, y2 = b.ss;
	ll x3 = c.ff, y3 = c.ss;
 
	ll lhs = (y2 - y1) * (x3 - x2);
	lhs -= (y3 - y2) * (x2 - x1);
 
	if(lhs == 0){
		return 0;
	}
	else if(lhs > 0){
		return 2; // left
	}
	else{
		return 1; // right
	}
}
 
ll dist(pii a, pii b){
	return (a.ff - b.ff) * (a.ff - b.ff) + (a.ss - b.ss) * (a.ss - b.ss);
}
 
bool cmp(pii x, pii y){
 
	ll o = getOriention(mn, x, y);
 
	if(o == 0){
		return (dist(mn, x) <= dist(mn, y));
	}
 
	return (o == 2? 1: 0);
}
 
void solve() {
    ll n;
    cin >> n;
 
    vector <pii> a(n);
 
    for(ll i = 0; i < n; ++i){
    	cin >> a[i].ff >> a[i].ss;
    }
 
    sort(a.begin(), a.end());
 
    mn = a[0];
    int mnId = 0;
    for(ll i = 0; i < n; ++i){
    	if(a[i].ss < mn.ss){
    		mn = a[i];
    		mnId = i;
    	}
    }
 
    swap(a[mnId], a[0]);
	sort(a.begin() + 1, a.end(), cmp);


	for(int i = 0; i < n; ++i){
		cout << a[i].ff << " " << a[i].ss << "\n";
	}
 
	stack <pii> st;
 
	st.push(a[0]);
	st.push(a[1]);
	st.push(a[2]);
 
	for(ll i = 3; i < n; ++i){
        pii z = a[i];
        while(st.size() >= 2){
            pii y = st.top(); st.pop();
            pii x = st.top(); st.push(y);
 
            if(getOriention(x, y, z) == 1){
                st.pop();
            }
            else break;
        }
        st.push(z);
    }

 	set <pii> ans;
	while(!st.empty()){
		pii tp = st.top();
		ans.insert(tp);
		st.pop();
	}

	cout << ans.size() << "\n";
	for(auto it : ans){
		cout << it.ff << " " << it.ss << "\n";
	}
	cout << "\n";
	
}
 
int main(){
    
    fast();
 
    solve();
 
    return 0;
}