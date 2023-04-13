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

		int  n;
		cin >> n;

		string s;
		cin >> s;

		if(n == 1){
			cout << "YES\n";
			continue;
		}

		vector <int> id;
		bool z = 1;

		for(int i = 0; i < n; ++i){
			if(s[i] == '1' && z){
				id.push_back(i);
				z = 0;
			}
			else if(s[i] == '0'){
				z = 1;
			}
		}

		bool pos = 1;

		for(int i = 0; i < id.size(); ++i){
			
			int cnt = 0;
			for(int j = id[i]; j < n; ++j){
				if(s[j] == '1'){
					++cnt;
				}
				else{
					break;
				}
			}

			// cout << id[i] << " : " << cnt << "\n";

			if(cnt % 2 == 1){
				pos = 0;
				// break;
			}
		}

		if(pos) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;	
}