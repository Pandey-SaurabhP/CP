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

// Solve

void update(int tl, int tr, int v, int id, int x, vector <int> &segTree){

    if(tl > tr) return;
    if(tl == tr){
        segTree[v] += x;
        return;
    }

    int mid = (tl + tr) >> 1;

    if(mid >= id){
        update(tl, mid, 2 * v + 1, id, x, segTree);
    }
    else{
        update(mid + 1, tr, 2 * v + 2, id, x, segTree);
    }

    segTree[v] = segTree[2 * v + 1] + segTree[2 * v + 2];
}

int query(int tl, int tr, int v, int l, int r, vector <int> &segTree){

    if(tl >= l && tr <= r){
        return segTree[v];
    }

    if(tl > r || tr < l){
        return 0;
    }

    int mid = (tl + tr) >> 1;

    return query(tl, mid, 2 * v + 1, l, r, segTree) +
            query(mid + 1, tr, 2 * v + 2, l, r, segTree);
}



void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    vector <pii> vc(n);
    for(int i = 0; i < n; ++i){
    	cin >> vc[i].ff >> vc[i].ss;
    }

    sort(vc.begin(), vc.end());

    // Coordinate compression
    map <int, int> mpr, mpc, rpm, cpm;
    int x = -1;
    for(auto it : vc){
    	if(!mpr.count(it.ff)){
    		mpr[it.ff] = ++x;
            rpm[x] = it.ff;
    	}
    }

    sort(vc.begin(), vc.end(), [] (pii a, pii b){
    	return a.ss < b.ss;
    });

    x = -1;
    for(auto it : vc){
    	if(!mpc.count(it.ss)){
    		mpc[it.ss] = ++x;
            cpm[x] = it.ss;
    	}
    }

    // Done

    vector <pii> nw(n);

    for(int i = 0; i < n; ++i){
    	nw[i] = {mpr[vc[i].ff], mpc[vc[i].ss]};
    	cout << nw[i].ff << " " << nw[i].ss << "\n";
    }


    vector <int> sgRow(4 * n, 0), sgCol(4 * n, 0);

    vector <int> row(n, -1), col(n, -1);

    for(auto it : nw){
        row[it.ff] = 1;
        col[it.ss] = 1;
        // update(0, n - 1, 0, it.ff, 1, sgRow);
        // update(0, n - 1, 0, it.ss, 1, sgCol);
    }

    // for(int i = 0; i < n; ++i){
    //     cout << query(0, n - 1, 0, i, i, sgRow) << " ";
    // }
    // cout << "\n";

    // for(int i = 0; i < n; ++i){
    //     cout << query(0, n - 1, 0, i, i, sgCol) << " ";
    // }
    // cout << "\n";

    int trs = 1, tre = a;
    int tcs = 1, tce = b;

    for(int i = 0; i < m; ++i){
        char ch; int xyz;
        cin >> ch >> xyz;

        if(ch == 'U'){
            // Remove the upper part
            // If there are elements from trs till trs + xyz - 1 th row then run a loop and check accordingly
            auto *abc = mpr.lower_bound(trs);

            cout << abc << "\n";

            if(abc <= trs + xyz - 1){
                // Run a for loop from xyz till trs + xyz - 1
                for(int j = rpm[abc]; rpm[abc] <= trs + xyz - 1; ++j){
                    
                }
            }

            trs = trs + xyz;

        }  
        else if(ch == 'D'){

        }
        else if(ch == 'L'){

        }
        else{

        }
    }

}

int main(){
    
    // fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}