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

void printpq( priority_queue <pii, vector <pii>, greater <pii>> pq){
	while(!pq.empty()){
		pii tp = pq.top();
		cout << tp.ss << " : " << tp.ff << "\n";
		pq.pop();
	}
}

void solve() {
    int n, t;
    cin >> n >> t;

    vector <int> a(n);
    read(a, i, n);


    map <int, int> mp;

    for(auto it : a){
    	mp[it]++;
    }

    int lo = 1;
    int hi = n;

    int gans = 0;

    while(lo <= hi){
    	int mid = (lo + hi) / 2;

    	int k = mid;

    	cout << "K : " << k << "\n";

    	
    	priority_queue <pii, vector <pii>, greater <pii>> pq;
	    for(auto it : mp){
	    	pq.push({it.ss, it.ff});
	    }

	    map <int, int> occured;
	    set <int> inq;

	    int ans = 0;

	    for(int i = 0; i < n; ++i){

	    	printpq(pq);
	    	for(auto it : inq){
	    		cout << it << " ";
	    	}
	    	cout << "\n\n\n";

	    	if(inq.count(a[i])){
	    		occured[a[i]]++;
	    	}
	    	else if(inq.size() < k){
	    		occured[a[i]]++;
	    		inq.insert(a[i]);
	    		++ans;
	    	}
	    	else{
	    		// Something needs to be removed, remove the one with least occurence
				pii tp = pq.top();

				while(inq.size() >= k){
					inq.erase(pq.top().ss);
					
				}
				inq.insert(a[i]);

				occured[a[i]]++;
				++ans;
	    	}

	    	if(a[i] == pq.top().ss){
	    		pii tp = pq.top();
				pq.pop();

				tp.ff -= occured[tp.ss];
				occured[tp.ss] = 0;
				pq.push(tp);
	    	}
	    }

	    if(ans > t){
	    	lo = mid + 1;
	    }
	    else if(ans <= t){
	    	hi = mid - 1;
	    	gans = mid;
	    }
    }

    cout << (gans == 0? -1: gans) << "\n";
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