#include <bits/stdc++.h>
using namespace std;

#define pb          push_back

typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

void solve() {
    int n, k, m;
    cin >> n >> k >> m;

    vector <pair <int, pii>> edge;

    for(int i = 0; i < m; ++i){
    	int u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;

    	edge.pb({w, {u, v}});
    }

    sort(edge.begin(), edge.end());
    reverse(edge.begin(), edge.end());

    // Can assign atmax k
    vector <int> assigned(n, 0);
    int ans = 0;

    for(int i = 0; i < m; ++i){

    	int u = edge[i].ss.ff;
    	int v = edge[i].ss.ss;

    	int w = edge[i].ff;

    	if(assigned[u] == k || assigned[v] == k){
    		continue;
    	}

    	assigned[u]++;
    	assigned[v]++;

    	ans += w;
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    solve();
    

    return 0;
}