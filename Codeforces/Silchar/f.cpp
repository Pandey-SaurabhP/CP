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
#define read(a, i, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(int i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

// Constants
const int mxn = 1e6 + 5;
const int mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve

void solve() {
 	int n;
 	cin >> n;

 	vector <string> a(n);
 	read(a, i, n);

 	vector <int> v(n);
 	read(v, i, n);

 	int cnt[10];

 	int ans = 0;

 	map <int, int> mp2;
 	map <int, int> mp;

 	map <int, int> andMask; // index and mask

 	for(int i = 0; i < n; ++i){
 		int cur = 0;
 		for(auto it : a[i]){
 			cur |= (1 << (it - '0'));
 		}

 		andMask[i] = cur;
 	}

 	map <int, int> orMask;

 	for(int i = 0; i < 1024; ++i){

 		for(int j = 0; j < n; ++j){
 			
 		}
 	}

 	for(int c = 0; c < 4; ++c){

 		vector <int> Index;

 		mp2.clear();
 		mp.clear();
 		

 		for(int i = 0; i < n; ++i){
 			if(v[i] != c){
 				Index.push_back(i);
 			}
 			else{
 				mp2[andMask[i]]++;
 			}
 		}

	 	for(int i = 0; i < 1024; ++i){
	 		set <int> st;

	 		for(int j = 0; j < Index.size(); ++j){

	 			for(auto k : a[Index[j]]){
	 				if((1 << (k - '0')) & i){
	 					st.insert(Index[j]);
	 				}
	 			}
	 		}

	 		mp[i] = st.size();
	 	}

	 	for(int i = 0; i < 1024; ++i){
	 		ans += mp2[i] * (Index.size() - mp[i]);
	 	}
 	}

 	cout << ans / 2 << "\n";
}

int main(){
    
    fast();

    solve();

    return 0;
}