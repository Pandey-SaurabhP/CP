#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 998244353;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;

        vector<bool> skip(n + 1);
        skip[n] = true;
        for (int i = 0; i < k; i++) {
            int a; cin >> a;
            skip[n - a] = true;
        }

        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            if (!skip[i]) ans = (ans * i) % MOD;
        }
        cout << ans << "\n";
    }
}