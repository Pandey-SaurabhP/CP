// pSaurabh
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6+ 6;

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

class dsu{
public:
	int par[mxn];
	int sz[mxn];

	dsu(int n){
		for(int i = 0; i < n; ++i){
			par[i] = i;
			sz[i] = 1;
		}
	}

	int getParent(int x){

		if(x == par[x]){
			return x;
		}

		return par[x] = getParent(par[x]);
	}

	void unite(int x, int y){
		int px = getParent(x);
		int py = getParent(y);

		if(px == py){
			return;
		}

		if(sz[px] >= sz[py]){
			par[px] = par[py];
			sz[px] += sz[py];
		}
		else{
			par[py] = par[px];
			sz[py] += sz[px];
		}
	}

	bool find(int x, int y){
		return getParent(x) == getParent(y);
	}

};

int main(){

	// fast();

	int n, q;
	cin >> n >> q;

	dsu d(n);

	for(int i = 0; i < q; ++i){
		string s;
		cin >> s;

		if(s == "union"){
			int x, y;
			cin >> x >> y;

			d.unite(x, y);
		}	
		else{
			int x, y;
			cin >> x >> y;

			if(d.find(x, y)){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}

	return 0;	
}