// pSaurabh
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main(){

	fast();

	ll t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector <int> a(n);
		read(a, n);

		map <int, int> mp;

		for(auto it : a){
			if(mp.find(it) == mp.end()){
				mp[it] = 0;
			}

			++mp[it];
		}

		int ans = n;

		for(auto it : mp){

			ans = min(ans, n - it.second);
			if(it.first % 2 == 0){
				ans = min(ans, n - it.second - mp[it.first + 1]);
			}
		}

		cout << ans << "\n";
	}

	return 0;	
}