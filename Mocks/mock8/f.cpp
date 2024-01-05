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
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

int lucky[mxn];
int ans[mxn];

int toNum(string x){
	int ans = 0;
	int mult = 1;

	for(int i = 5; i >= 0; --i){
		ans += (x[i] - '0') * mult;
		mult *= 10;
	}

	return ans;
}

void luckyNumber(int x){
	string ans;

	while(x){
		ans += (x % 10) + '0';
		x /= 10;
	}

	while(ans.size() != 6){
		ans += '0';
	}
	
	int left = (ans[0] + ans[1] + ans[2]) - (3 * '0');
	int right = (ans[3] + ans[4] + ans[5]) - (3 * '0');

	lucky[toNum(ans)] = abs(left - right);
}



void solve() {
    for(int i = 0; i <= 999999; ++i){
    	luckyNumber(i);
    }

    vector <int> cnt(30, 0);

    ans[0] = 0;
    cnt[0] = 1;

    for(int i = 1; i < mxn; ++i){

    	// cout << i << " : " << lucky[i] << " " << lasts[lucky[i] - 1] << " " << cnt[lucky[i] - 1] << "\n";

    	if(lucky[i] == 0){
    		ans[i] = 0;
    		cnt[0]++;
    	}
    	else{

	    	for(int j = 0; j < lucky[i]; ++j){
	    		ans[i] += cnt[j];
	    	}

	    	cnt[lucky[i]]++;
    	}
    }

    int t;
    cin >> t;

    while(t--){
    	string x;
    	cin >> x;

    	cout << ans[toNum(x)] << "\n";
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}