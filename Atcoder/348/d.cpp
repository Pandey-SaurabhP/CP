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

int en[205][205];
int mx[205][205];

int dd[5] = {0, 1, 0, -1, 0};

void solve() {
	memset(en, 0, sizeof(en));
	memset(mx, 0, sizeof(mx));

	for(int i = 0; i < 205; ++i){
		for(int j = 0; j < 205; ++j){
			mx[i][j] = INT_MIN;
		}
	}

    
    int h, w;
    cin >> h >> w;



    vector <string> s(h);
    read(s, i, h);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
    	int u, v, w;
    	cin >> u >> v >> w;

    	--u, --v;

    	en[u][v] = w;
    }

    int sx, sy, tx, ty;
    
    for(int i = 0; i < h; ++i){
    	for(int j = 0 ; j < w; ++j){
    		if(s[i][j] == 'S'){
    			sx = i;
    			sy = j;
    		}

    		if(s[i][j] == 'T'){
    			tx = i;
    			ty = j;
    		}
    	}
    }

    queue <pair <pii, int>> q;
    q.push({{sx, sy}, en[sx][sy]});

    mx[sx][sy] = en[sx][sy];
    en[sx][sy] = 0;



    while(!q.empty()){

    	auto fr = q.front();
    	q.pop();

    	int x = fr.ff.ff;
    	int y = fr.ff.ss;
    	int e = fr.ss;

    	// cout << x << " " << y << " " << e << "\n";


    	if(s[x][y] == 'T'){
    		cout << "Yes";
    		return;
    	}


    	if(en[x][y] > e){
    		e = en[x][y];
    		en[x][y] = 0;
    	}

    	mx[x][y] = max(mx[x][y], e);

    	for(int i = 0; i < 4; ++i){
    		int nx = x + dd[i];
    		int ny = y + dd[i + 1];

    		if(nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] != '#'){
    			if(mx[nx][ny] < e - 1){
    				q.push({{nx, ny}, e - 1});
    			}
    		}
    	}
    }

    cout << "No";
}

int main(){
    
    solve();

    return 0;
}