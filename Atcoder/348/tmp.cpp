#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void(0)
#endif

using namespace std;

typedef long long ll;
#define all(x) begin(x), end(x)
constexpr int INF = (1 << 30) - 1;
constexpr long long IINF = (1LL << 60) - 1;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
    auto sep = "";
    for (const auto& x : v) os << exchange(sep, " ") << x;
    return os;
}

template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x and (x = forward<U>(y), true); }

template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = forward<U>(y), true); }

template <class T> void mkuni(vector<T>& v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <class T> int lwb(const vector<T>& v, const T& x) { return lower_bound(begin(v), end(v), x) - begin(v); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    cin >> S;
    int N;
    cin >> N;
    vector energy(H, vector<int>(W, -1));
    for (; N--;) {
        int R, C, E;
        cin >> R >> C >> E;
        energy[R - 1][C - 1] = E;
    }

    int sx = -1, sy = -1, tx = -1, ty = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') sx = i, sy = j;
            if (S[i][j] == 'T') tx = i, ty = j;
        }
    }
    vector dp(H, vector<int>(W, -INF));
    priority_queue<tuple<int, int, int>> pq;
    dp[sx][sy] = 0;
    pq.emplace(dp[sx][sy], sx, sy);
    while (not pq.empty()) {
        auto [val, x, y] = pq.top();
        pq.pop();
        if (dp[x][y] != val) continue;
        if (chmax(dp[x][y], energy[x][y])) {
            pq.emplace(dp[x][y], x, y);
            continue;
        }
        if (val == 0) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 or H <= nx or ny < 0 or W <= ny) continue;
            if (S[nx][ny] == '#') continue;
            if (chmax(dp[nx][ny], val - 1)) pq.emplace(dp[nx][ny], nx, ny);
        }
    }

    cout << (dp[tx][ty] >= 0 ? "Yes" : "No") << '\n';
    return 0;
}