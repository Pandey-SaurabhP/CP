/*----------------------- Directives -----------------------*/
#include <bits/stdc++.h>

/*----------------------- Namespaces -----------------------*/
using namespace std;

/*------------------------- Macros -------------------------*/
#define endl        '\n'
#define pb          push_back
#define pf          push_front
#define mem(a,i)    memset(a,i,sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(),v.end()
#define rall(v)     v.rbegin(),v.rend()
#define w(t)        int t=1,tc=1;cin>>t;while(t--)

/*-------------------- Type Definitions --------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*-------------------------- Maths -------------------------*/
const int MOD = 1000*1000*1000 + 7; // for big mod
template <typename T> inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;} // better than __gcd
template <typename T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
template <typename T> inline bool isPrime(T n){for (T i=2;i*i<=n;i++) if(n%i==0) return false; return n>1;}

/*-------------------------- SOLVE -------------------------*/
vector<pair<int, int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid(int i, int j, int n, int m) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    set<pair<int, int>> freee;
    for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) freee.insert({i, j});

    queue<pair<int, int>> _q;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--; y--;
        _q.push({x, y});
        freee.erase({x, y});
    }

    vector<pair<int, int>> free(all(freee));

    if (m == 0) return cout << 2 * n << endl, void();
    else if (m == 2 * n) return cout << 0 << endl, void();
    else if (m == 2 * n - 1) return cout << (k >= 1 ? 1 : 0) << endl, void();

    int vis[2][25];

    int ans = 0;
    for (int m = 0; m < (1 << free.size()); m++) {
        if (__builtin_popcount(m) > k) continue;
        set<pair<int, int>> blocked;
        for (int i = 0; i < free.size(); i++) {
            if (m & (1 << i)) {
                blocked.insert(free[i]);
            }
        }

        int cnt = 0;
        mem(vis, 0);
        queue<pair<int, int>> q = _q;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (vis[i][j]) continue;
            cnt++;
            vis[i][j] = 1;
            for (auto &[x, y] : d) {
                int r = i + x, c = j + y;
                if (valid(r, c, 2, n) && !blocked.count({r, c})) {
                    q.push({r, c});
                    vis[r][c] = 1;
                }
            }
        }
        ans = max(ans, 2 * n - cnt);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // w(t) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        // tc++;
    // }

    return 0;
}