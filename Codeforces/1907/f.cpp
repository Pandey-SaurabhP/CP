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


int isCyclicSorted(vector <int> &a, int n){
	int mxId = 0;

	for(int i = 0; i < n - 1; ++i){
		if(a[i] > a[i + 1]){
			mxId = i + 1;
			break;
		}
	}

	// print(a, i, n);
	// cout << mxId << "<-\n";

	for(int i = mxId; i < mxId + n - 1; ++i){
		if(a[i % n] > a[(i + 1) % n]){
			return -1;
		}
	}

	int illSort = -1;

	for(int i = 0; i < n - 1; ++i){
		if(a[i] > a[i + 1]){
			return i + 1;
		}
	}

	return illSort;
}

bool isSorted(vector <int> &a, int n){

	for(int i = 0; i < n - 1; ++i){
		if(a[i] > a[i + 1]){
			return 0;
		}
	}

	return 1;
}

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    if(isSorted(a, n)){
    	cout << 0 << "\n";
    	return;
    }

    int id1 = isCyclicSorted(a, n);
    reverse(a.begin(), a.end());

    if(isSorted(a, n)){
    	cout << 1 << "\n";
    	return;
    }

    int id2 = isCyclicSorted(a, n);

    if(id1 == -1 && id2 == -1){
    	cout << -1 << "\n";
    }
    else if(id2 == -1){
    	// forward exists

    	int ans = min(2 + id1, n - id1);
    	cout << ans << "\n";
    }
    else if(id1 == -1){

    	id2 = n - id2 - 1;
    	// reverse exists

    	int ans = min(1 + (n - id2 - 1), 2 + id2);
    	cout << ans << "\n";
    }
    else{

    	id2 = n - id2 - 1;

    	int a1 = min(2 + id1, n - id1);
    	int a2 = min(1 + (n - id2 - 1), 2 + id2);

    	cout << min(a1, a2) << "\n";
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