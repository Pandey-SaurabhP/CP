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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
int a[2][12];
int b[2][12];

int n, m, k;



void floodfill(int i, int j){
	if(i >= 2 || j >= n || i < 0 ||  j < 0 || b[i][j] == 3){
		return;
	}

	if(b[i][j] == 2){
		return;
	}

	b[i][j] = 3;

	floodfill(i + 1, j);
	floodfill(i - 1, j);
	floodfill(i, j + 1);
	floodfill(i, j - 1);

}

int check(int k){
	int cntk = 0;

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			cntk += (a[i][j] == 2);
		}
	}

	if(cntk > k) return -1;

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			b[i][j] = a[i][j];
		}
	}

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			if(b[i][j] == 1) floodfill(i, j);
		}
	}

	int cnt = 0;

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < n; ++j){
			cnt += (b[i][j] == 2 || b[i][j] == 0);
		}	
	}

	return cnt;

}

void solve() {
    cin >> n >> m >> k;

    for(int i = 0; i < m; ++i){
    	int x, y;
    	cin >> x >> y;
    	--x, --y;

    	a[x][y] = 1;
    }

    vector <pii> free;
    for(int i = 0; i < 2; ++i){
    	for(int j = 0; j < n; ++j){
    		if(a[i][j] == 0){
    			free.pb({i, j});
    		}
    	}
    }

    int sz = free.size();
    int gans = 0;

    for(int i = 0; i < (1 << sz); ++i){

    	int x = i;

    	for(int j = 0; j < 25; j++){
    		if((1 << j) & x){
    			a[free[j].ff][free[j].ss] = 2;
    		}
    	}

    	// for(int i = 0; i < 2; ++i){
    	// 	for(int j = 0; j < n; ++j){
    	// 		cout << a[i][j] << " ";
    	// 	}
    	// 	cout << "\n";
    	// }
    	// cout << "\n";

    	int ans = check(k);

    	if(ans != -1){
    		gans = max(ans, gans);
    	}

    	for(int j = 0; j < 25; j++){
    		if((1 << j) & x){
    			a[free[j].ff][free[j].ss] = 0;
    		}
    	}
    }

    cout << gans << "\n";
}

int main(){
    
    // fast();

    solve();

    return 0;
}