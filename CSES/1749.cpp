#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define pbdset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
  
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

    vector <int> a(n);
    read(a, i, n);

    pbdset st;

    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;

        int lo = 1;
        int hi = n;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            int left = mid - st.order_of_key(mid + 1);

            if(left == x){
                // Potential Answer
                ans = mid;
                hi = mid - 1;
            }
            else if(left > x){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        // cout << ans << " : " << a[ans - 1] << "\n";
        cout << a[ans - 1] << " ";
        st.insert(ans);
    }
}

int main(){
    
    fast();

    solve();

    return 0;
}