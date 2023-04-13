// pSaurabh
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << "\n"; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const int mxn = 1e5 + 5;

void fast(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int dp1[mxn];
int dp2[mxn];

int solve1(int i, vector <int> &a, vector <int> &b, int &n){

	if(i == n){
		return 0;
	}

	if(dp1[i] != INT_MIN){
		return dp1[i];
	}

	int a1 = solve1(i + 1, a, b, n) + a[i];
	int a2 = solve1(i + 1, a, b, n) - b[i];

	a1 += 26;
	a2 += 26;

	a1 %= 26;
	a2 %= 26;

	return dp1[i] = min(a1, a2);
}


int main(){

	// fast();

	ll t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;

		string a, b;
		cin >> a >> b;

		for(int i = 0; i <= n + 5; ++i){
			dp1[i] = INT_MIN;
		}
		vector <int> v1(n), v2(n);

		for(int i = 0; i < n; ++i){

			if(b[i] >= a[i]){
				v1[i] = b[i] - a[i];
			}
			else{
				v1[i] = ('z' - a[i]) + (b[i] - 'a') + 1;
			}

			if(a[i] >= b[i]){
				v2[i] = a[i] - b[i];
			}
			else{
				v2[i] = ('z' - b[i]) + (a[i] - 'a') + 1;
			}
		}

		// print(v1, n);
		// print(v2, n);

		int ans = solve1(0, v1, v2, n);

		if(ans > 13){
			ans -= 26;
		}

		cout << abs(ans) << "\n";
	}

	return 0;	
}