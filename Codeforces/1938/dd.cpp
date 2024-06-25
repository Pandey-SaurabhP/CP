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
ll min_cost_of_array(vector<ll>& nums) {
    ll n = nums.size();

    // Calculate prefix sums
    vector<ll> prefix_sums(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1];
    }

    // Initialize dp array to store minimum cost
    vector<ll> dp(n + 1, INT_MAX);
    dp[0] = 0;

    // Iterate over all possible blocked elements
    for (ll b = 1; b <= n; ++b) {
        // Calculate the cost of blocking elements up to index b
        ll blocked_sum = prefix_sums[b];

        // Calculate the cost of dividing the array into segments
        ll max_segment_sum = 0;
        for (ll i = b; i <= n; ++i) {
            max_segment_sum = max(max_segment_sum, prefix_sums[i] - prefix_sums[b - 1]);
        }

        // Update the dp array with the minimum cost

        cout << b << " : " << blocked_sum << " " << 
        dp[b] = min(dp[b - 1], max(blocked_sum, max_segment_sum));
    }

    // The minimum cost is stored in dp[n]
    return dp[n];
}

void solve() {
    ll n;
    cin >> n;

    vector <ll> a(n);
    read(a, i, n);

    cout << min_cost_of_array(a) << "\n";
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