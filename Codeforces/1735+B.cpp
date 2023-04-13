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

		int mn = INT_MAX;

		for(int i = 0; i < n; ++i){
			mn = min(a[i], mn);
		}

		int mnReq = 2 * mn - 1;
		int ans = 0;

		for(int i = 0; i < n; ++i){
			if(a[i] > mnReq){
				int prts = (a[i] + mnReq - 1) / mnReq;
				ans += (prts - 1);
			}
		}

		cout << ans << "\n";
	}

	return 0;	
}