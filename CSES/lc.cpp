#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

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

ll getInvCount(vector <ll> &arr, ll n)
{
    ll inv_count = 0;
    for (ll i = 0; i < n - 1; i++)
        for (ll j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

ll factorial(ll x){
	ll ans = 1;

	for(ll i = 1; i <= x; ++i){
		ans *= i;
	}
	return ans;
}

ll slv(vector <pii> &r, ll m){
	sort(r.begin(), r.end());
	ll lg = 0;

	map <ll, ll> mp;
	set <ll> st;

	for(ll i = 0; i < m; ++i){
		lg = max(r[i].ff + 1, lg);
		mp[r[i].ff + 1] = r[i].ss;
		st.insert(r[i].ff + 1);
	}

	vector <vector <ll>> t(301, vector <ll> (301, 0));
	t[0][0] = 1;
	
	for (int i = 1; i <= lg; ++i) {
        for (int j = 0; j <= mp[lg]; ++j) {
        	cout << i << " " << j << " " << mp[i] << " ";
            	if(st.count(i) && j != mp[i]){
            		cout << "Fail\n";
            		t[i][j] = 0;
            		continue;
            	}
            	cout << "\n";

                t[i][j] = 0;
                for (int k = 0; k <= min(j, i - 1); ++k) {
                    t[i][j] += t[i - 1][j - k];
                }
            
        }
    }

    cout << 




	for(ll i = 0; i < 10; ++i){
		for(ll j = 0; j < 20; ++j){
			cout << t[i][j] << " ";
		}
		cout << "\n";
	}

}


void solve() {
    

    ll n, m;
    cin >> n >> m;

    vector <pii> r(m);
    for(ll i = 0; i < m; ++i){
    	cin >> r[i].ff >> r[i].ss;
    }

    slv(r, m);
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