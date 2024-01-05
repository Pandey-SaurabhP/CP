#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

bool a[10001][10001];
bool vis[10001][10001];

bool bfs(int n, int m){
	
	queue <pii> q;
	q.push({0, 0});	

	int x, y;


	while(!q.empty()){

		pii tp = q.front();
		q.pop();

		if(a[tp.ff][tp.ss] == 1){
			continue;
		}


		x = tp.ff;
		y = tp.ss;

		cout << x << " " << y << "\n";

		if(x == n - 1 && y == m - 1){
			return 1;
		}

		vis[x][y] = 1;

		if(x - 1 >= 0 && !vis[x - 1][y] && a[x - 1][y] != 1){
			vis[x - 1][y] = 1;
			q.push({x - 1, y});
		}

		if(x - 1 >= 0 && y + 1 < m && !vis[x - 1][y + 1] && a[x - 1][y + 1] != 1){
			vis[x - 1][y + 1] = 1;
			q.push({x - 1, y + 1});
		}

		if(y + 1 < m && !vis[x][y + 1] && a[x][y + 1] != 1){
			vis[x][y + 1] = 1;
			q.push({x, y + 1});
		}

		if(x + 1 < n && y + 1 < m && !vis[x + 1][y + 1] && a[x + 1][y + 1] != 1){
			vis[x + 1][y + 1] = 1;
			q.push({x + 1, y + 1});
		}

		if(x + 1 < n && !vis[x + 1][y] && a[x + 1][y] != 1){
			vis[x + 1][y] = 1;
			q.push({x + 1, y});
		}

		if(x + 1 < n && y - 1 >= 0 && !vis[x + 1][y - 1] && a[x + 1][y - 1] != 1){
			vis[x + 1][y - 1] = 1;
			q.push({x + 1, y - 1});
		}

		if(y - 1 >= 0 && !vis[x][y - 1] && a[x][y - 1] != 1){
			vis[x][y - 1] = 1;
			q.push({x, y - 1});
		}

		if(x - 1 >= 0 && y - 1 >= 0 && !vis[x - 1][y - 1] && a[x - 1][y - 1] != 1){
			vis[x - 1][y - 1] = 1;
			q.push({x - 1, y - 1});
		}
	}

	return 0;
}

void solve() {


	for(int i = 0; i < 10001; ++i){
		for(int j = 0; j < 10001; ++j){
			a[i][j] = 0;
			vis[i][j] = 0;
		}
	}


    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < k; ++i){
    	int r, c, x;
    	cin >> r >> c >> x;

    	--r, --c;

    	// x = max(x - 1, 0);

    	int startr = r;
    	int startc = c - x;

    	while(startc != c + 1){
    		if(startc >= 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc >= 0 && startr < 0){
    			a[0][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc < 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][0] = 1;
    		}
    		else{
    			a[0][0] = 1;
    		}

    		++startc;
    		--startr;
    	}

    	--startc;
    	++startr;

    	while(startr != r + 1){
    		if(startc >= 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc >= 0 && startr < 0){
    			a[0][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc < 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][0] = 1;
    		}
    		else{
    			a[0][0] = 1;
    		}

    		++startc;
    		++startr;
    	}

    	--startc;
    	--startr;

    	while(startc != c - 1){
    		if(startc >= 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc >= 0 && startr < 0){
    			a[0][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc < 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][0] = 1;
    		}
    		else{
    			a[0][0] = 1;
    		}

    		--startc;
    		++startr;
    	}

    	++startc;
    	--startr;

    	while(startr != r - 1){
    		if(startc >= 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc >= 0 && startr < 0){
    			a[0][(startc < m? startc: m - 1)] = 1;
    		}
    		else if(startc < 0 && startr >= 0){
    			a[(startr < n? startr: n - 1)][0] = 1;
    		}
    		else{
    			a[0][0] = 1;
    		}

    		--startc;
    		--startr;
    	}
    }

    for(int i = 0; i < n; ++i){
    	print(a[i], j, m);
    }

    if(bfs(n, m)){
    	cout << "S";
    }
    else{
    	cout << "N";
    }
}

int main(){
    
    // fast();

    solve();

    return 0;
}