// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

typedef long long int ll;
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
		ll n;
		cin >> n;

		vector <ll> a(n), b(n);
		read(a, n);
		read(b, n);

		ll ans = 0;

		for(ll i = 0; i < n; ++i){
			ans += a[i];
		}

		vector <pair <ll, ll>> vc;

		for(ll i = 0; i < n; ++i){
			vc.push_back({b[i], i});
		}

		sort(vc.begin(), vc.end());

		ll lm = 0;
		ll rm = n - 1;

		set <ll> disapp;

		for(ll i = 0; i < n; ++i){

			if(vc[i].second == lm && vc[i].second == rm){
				ans += 0;
			}
			else if(vc[i].second == lm || vc[i].second == rm){
				ans += vc[i].first;
			}
			else{
				ans += (vc[i].first * 2);
			}

			disapp.insert(vc[i].second);

			while(disapp.count(lm)){
				++lm;
			}

			while(disapp.count(rm)){
				--rm;
			}
		}

		cout << ans << "\n";


	}

	return 0;	
}