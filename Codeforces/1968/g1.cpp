#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(int i = x; i < n; ++i)
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

int ans[200005];

// Solve
vector <int> getLPS(string s){
 
	vector <int> lps(s.size() + 1, 0);
	lps[0] = 0;
 
	int i = 0, j = 1;
 
	while(j < s.size()){
		if(s[i] == s[j]){
			lps[j] = ++i;
			++j;
		}
		else{
			if(i != 0){
				i = lps[i - 1];
			}
			else{
				lps[j] = 0;
				++j;
			}
		}
	}
 
	return lps;
}


bool valid(int mid, string &s, int n, int k){

	string p;

	for(int i = 0; i < mid; ++i){
		p += s[i];
	}

	vector <int> lps = getLPS(p);

	// print(lps, i, lps.size());

	int i = 0, j = 0;
    int counter = 0;
 
    while(s.size() - i >= p.size() - j){
 
    	if(s[i] == p[j]){
    		++i, ++j;
    	}
 
    	if(j == p.size()){
    		++counter;
    		j = 0;
    	}
    	else if(i < s.size() && s[i] != p[j]){
    		if(j != 0){
    			j = lps[j - 1];
    		}
    		else{
    			++i;
    		}
    	}
 
    }

    if(counter >= k){
    	return 1;
    }

    return 0;

    // cout << counter << "\n";
}

int getAns(string &s, int k){
	int n = s.size();

	int lo = 1;
    int hi = n;
    int ans = 0;


    while(lo <= hi){
    	int mid = (lo + hi) / 2;

    	// cout << mid << "\n"

    	if(valid(mid, s, n, k)){
    		lo = mid + 1;
    		ans = mid;
    	}
    	else{
    		hi = mid - 1;
    	}
    }

    return ans;
}

void solve() {
    int n, l, r;
    cin >> n >> l >> r;

    int tl = l;
    int tr = r;

    string s;
    cin >> s;

    int mx = getAns(s, l);
    int init = mx;
    int cans = mx;

    vector <pii> tmp;
    tmp.pb({l, mx});

    // for(int i = l; i <= r; ++i){
    // 	cout << getAns(s, i) << " ";
    // }
    // cout << "\n\n";

    while(cans != 0){

    	int lo = l + 1;
    	int hi = r;

    	if(lo > hi) break;
    	int cid = r;

    	while(lo <= hi){

    		int mid = (lo + hi) >> ;
    		int cur = getAns(s, mid);

    		if(cur < mx){
    			cans = cur;
    			cid = mid;
    			hi = mid - 1;
    		}
    		else{
    			lo = mid + 1;
    		}
    	}
    	mx = cans;
    	l = cid;

    	tmp.pb({cid, cans});
    }

    for(int i = l; i <= r; ++i){
    	ans[i] = -1;
    }

    for(int i = 0; i < tmp.size(); ++i){
    	// cout << tmp[i].ff << " " << tmp[i].ss << "\n";
    	ans[tmp[i].ff] = tmp[i].ss;
    }

    // print(ans, i, n + 1);

    int lst = init;
    
    for(int i = tl; i <= tr; ++i){
    	if(ans[i] == -1){
    		ans[i] = lst;
    	}
    	else{
    		lst = ans[i];
    	}
    }

    for(int i = tl; i <= tr; ++i){
    	cout << ans[i] << " ";
    }
    cout << "\n";

    // print(tmp, i, tmp.size());

    // cout << ans << "\n";

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