// pSaurabh
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

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

		string s;
		cin >> s;

		ll n = s.size();

		vector <ll> cont(n);

		for(ll i = 0; i < n; ++i){
			cont[i] = (n - i) * (i + 1);
		}

		ll i = 0;
		ll delta = 0;

		vector <ll> change;

		while(i < cont.size()){
			if(s[i] == '1'){
				delta -= cont[i];
			}
			else{
				delta += cont[i];
			}

			change.push_back(delta);
			++i;
		}

		ll m = change.size();


		ll sm = 0;
		for(ll i = 0; i < n; ++i){
			if(s[i] == '1'){
				sm += cont[i];
			}
		}

		ll dd = 0;
		ll mn = 0;

		for(ll i = 0; i < n; ++i){
			
			dd = max(max(change[i], change[i] - mn), dd);
			mn = min(mn, change[i]);
		}

		cout << sm + dd << "\n";
	}

	return 0;	
}