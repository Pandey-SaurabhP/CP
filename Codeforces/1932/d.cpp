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

void solve() {
    int n;
    cin >> n;

    char trump;
    cin >> trump;

    vector <string> s(2 * n);

    rep(i, 0, 2 * n - 1){
    	cin >> s[i];
    }

    vector <string> trumps;
    vector <vector <string>> store(256);

    int t = 0;
    vector <int> cnt(256, 0);

    for(auto it : s){
    	if(it[1] == trump){
    		trumps.pb(it);
    		++t;
    	}
    	else{
    		store[it[1]].pb(it);
    		cnt[it[1]]++;
    		cnt[it[1]] %= 2;
    	}
    }


    int left = accumulate(cnt.begin(), cnt.end(), 0);

    if(t >= left){
    	for(int i = 0; i < 256; ++i){
    		sort(store[i].begin(), store[i].end());
    	}

    	for(int i = 1; i < store['C'].size(); i += 2){
    		cout << store['C'][i - 1] << " " << store['C'][i] << "\n";
    	}
    	for(int i = 1; i < store['D'].size(); i += 2){
    		cout << store['D'][i - 1] << " " << store['D'][i] << "\n";
    	}
    	for(int i = 1; i < store['H'].size(); i += 2){
    		cout << store['H'][i - 1] << " " << store['H'][i] << "\n";
    	}
    	for(int i = 1; i < store['S'].size(); i += 2){
    		cout << store['S'][i - 1] << " " << store['S'][i] << "\n";
    	}

    	sort(trumps.begin(), trumps.end());

    	int x = 0;
    	if(store['C'].size() % 2 == 1){
    		cout << store['C'][store['C'].size() - 1] << " " << trumps[x++] << "\n"; 
    	}
    	if(store['D'].size() % 2 == 1){
    		cout << store['D'][store['D'].size() - 1] << " " << trumps[x++] << "\n"; 
    	}
    	if(store['H'].size() % 2 == 1){
    		cout << store['H'][store['H'].size() - 1] << " " << trumps[x++] << "\n"; 
    	}
    	if(store['S'].size() % 2 == 1){
    		cout << store['S'][store['S'].size() - 1] << " " << trumps[x++] << "\n"; 
    	}

    	for(int i = x + 1; i < trumps.size(); i += 2){
    		cout << trumps[i - 1] << " " << trumps[i] << "\n";
    	}
    }
    else{
    	cout << "IMPOSSIBLE\n";
    }
    

}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}