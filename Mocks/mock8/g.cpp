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
const ll mxn = 1e3 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
	int n;
	cin >> n;


	bool ok = 1;

	vector <pii> vc(n - 1);
	vector <int> cnt(n, 0);

	map <pii, int> mp;

	for(int i = 0; i < n - 1; ++i){
		int x, y;
		cin >> x >> y;

		if(x > y){
			swap(x, y);
		}

		if(x == y){
			ok = 0;
		}
		if(y != n){
			ok = 0;
		}

		cnt[x]++;

		vc[i] = {x, y};
		mp[{x, y}]++;
	}


	if(!ok){
		cout << "NO\n";
		return;
	}

	vector <int> ans(n, -1);
	ans[n - 1] = n;
	int lst = n - 1;

	vector <int> notin;

	for(int i = n - 1; i >= 1; --i){
		if(cnt[i] >= 1){
			lst -= cnt[i];

			ans[lst] = i;
		}
		else{
			notin.pb(i);
		}
	}

	int y = 0;

	for(int i = n - 1; i >= 0; --i){
		if(ans[i] == -1){
			int x = notin[y]; ++y;
			ans[i] = x;
		}
	}

	vector <int> pre(n);
	pre[0] = ans[0];
	for(int i = 1; i < n; ++i){
		pre[i] = max(pre[i - 1], ans[i]);
	}

	vector <int> suff(n);
	suff[n - 1] = ans[n - 1];

	for(int i = n - 2; i >= 0; --i){
		suff[i] = max(suff[i + 1], ans[i]);
	}

	for(int i = 0; i < n - 1; ++i){
		if(mp[{pre[i], suff[i + 1]}] > 0){
			--mp[{pre[i], suff[i + 1]}];
		}
		else{
			// Not ok
			ok = 0;
			break;
		}
	}

	if(!ok){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";

		for(int i = 0; i < n - 1; ++i){
			cout << ans[i] << " " << ans[i + 1] << "\n";
		}
	}
}

int main(){
    
    // fast();
    solve();
    
    return 0;
}