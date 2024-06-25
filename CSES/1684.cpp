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
map <ll, vector <ll>> graph, rev;
set <ll> vis1, vis2;
stack <ll> order;

vector <int> assigned(mxn, -1);

void dfs1(ll root){

	vis1.insert(root);

	for(auto it : graph[root]){
		if(!vis1.count(it)){
			dfs1(it);
		}
	}

	order.push(root);
}

vector <set <ll>> comps;
set <ll> tmp;

void dfs2(ll root){
	vis2.insert(root);
	tmp.insert(root);

	for(auto it : rev[root]){
		if(!vis2.count(it)){
			dfs2(it);
		}
	}
}

set <int> vis4;

void checkList(int x, int root){

	vis4.insert(root);

	if(assigned[abs(root)] == -1){
		if(root < 0){
			assigned[abs(root)] = 0;
		}
		else{
			assigned[abs(root)] = 1;
		}
	}

	for(auto it : rev[root]){
		if(comps[x].count(it) && !vis4.count(it)){
			checkList(x, it);
		}
	}

}

void solve() {
    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < n; ++i){
    	char t1, t2;
    	ll x1, x2;
    	bool b1, b2;

    	cin >> t1 >> x1 >> t2 >> x2;

    	if(t1 == '-') x1 = -x1;
    	if(t2 == '-') x2 = -x2;

    	graph[-x1].pb(x2);
    	rev[x2].pb(-x1);

    	graph[-x2].pb(x1);
    	rev[x1].pb(-x2);
    }

    // Now find SCC

    for(ll i = -m; i <= m; ++i){
    	if(!vis1.count(i)){
    		dfs1(i);
    	}
    }

    while(!order.empty()){

    	ll tp = order.top();
    	order.pop();

    	if(!vis2.count(tp)){
    		tmp.clear();
    		dfs2(tp);
    		comps.pb(tmp);
    	}
    }

    for(ll i = 0; i < comps.size(); ++i){
    	cout << i << " : ";
    	for(auto it : comps[i]){
    		cout << it << " ";
    	}
    	cout << "\n";
    }
    cout << "\n";




}

int main(){
    
    fast();

    solve();

    return 0;
}