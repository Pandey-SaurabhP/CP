
#include <bits/stdc++.h>

using namespace std;

#define endl        '\n'
#define pb          push_back
#define pf          push_front
#define int         long long
#define mem(a,i)    memset(a,i,sizeof(a))
#define ff          first
#define ss          second
#define all(v)      v.begin(),v.end()
#define rall(v)     v.rbegin(),v.rend()
#define w(t)        int t=1,tc=1;cin>>t;while(t--)

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int MOD = 1000*1000*1000 + 7; // for big mod
template <typename T> inline T gcd(T a, T b){T c;while (b){c = b;b = a % b;a = c;}return a;} // better than __gcd
template <typename T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
template <typename T> inline bool isPrime(T n){for (T i=2;i*i<=n;i++) if(n%i==0) return false; return n>1;}

struct sum_kth_smallest {
    struct Node {
        long long sum;
        int cnt;
        int lCh, rCh;//children, indexes into `tree`
    };

    int mn, mx;
    vector<int> roots;
    deque<Node> tree;

    sum_kth_smallest(const vector<ll>& arr) : mn(INT_MAX), mx(INT_MIN), roots(arr.size() + 1, 0) {
        tree.push_back({0, 0, 0}); //acts as null
        for (int val : arr) mn = min(mn, val), mx = max(mx, val);
        for (int i = 0; i < (int)arr.size(); i++)
            roots[i + 1] = update(roots[i], -mx, mx, arr[i]);
    }
    int update(int v, int tl, int tr, int idx) {
        if (tl == tr) {
            tree.push_back({tree[v].sum + tl, tree[v].cnt + 1, 0, 0});
            return tree.size() - 1;
        }
        int tm = tl + (tr - tl) / 2;
        int lCh = tree[v].lCh;
        int rCh = tree[v].rCh;
        if (idx <= tm)
            lCh = update(lCh, tl, tm, idx);
        else
            rCh = update(rCh, tm + 1, tr, idx);
        tree.push_back({tree[lCh].sum + tree[rCh].sum, tree[lCh].cnt + tree[rCh].cnt, lCh, rCh});
        return tree.size() - 1;
    }


    /* find kth smallest number among arr[l], arr[l+1], ..., arr[r]
     * k is 1-based, so find_kth(l,r,1) returns the min
     */
    int query(int l, int r, int k) const {
        assert(1 <= k && k <= r - l + 1); //note this condition implies L <= R
        assert(0 <= l && r + 1 < (int)roots.size());
        return query(roots[l], roots[r + 1], -mx, mx, k);
    }
    int query(int vl, int vr, int tl, int tr, int k) const {
        if (tl == tr)
            return tl;
        int tm = tl + (tr - tl) / 2;
        int left_count = tree[tree[vr].lCh].cnt - tree[tree[vl].lCh].cnt;
        if (left_count >= k) return query(tree[vl].lCh, tree[vr].lCh, tl, tm, k);
        return query(tree[vl].rCh, tree[vr].rCh, tm + 1, tr, k - left_count);
    }

    /* find *sum* of k smallest numbers among arr[l], arr[l+1], ..., arr[r]
     * k is 1-based, so find_kth(l,r,1) returns the min
     */
    long long query_sum(int l, int r, int k) const {
        assert(1 <= k && k <= r - l + 1); //note this condition implies L <= R
        assert(0 <= l && r + 1 < (int)roots.size());
        return query_sum(roots[l], roots[r + 1], -mx, mx, k);
    }
    long long  query_sum(int vl, int vr, int tl, int tr, int k) const {
        if (tl == tr)
            return 1LL * tl * k;
        int tm = tl + (tr - tl) / 2;
        int left_count = tree[tree[vr].lCh].cnt - tree[tree[vl].lCh].cnt;
        long long left_sum = tree[tree[vr].lCh].sum - tree[tree[vl].lCh].sum;
        if (left_count >= k) return query_sum(tree[vl].lCh, tree[vr].lCh, tl, tm, k);
        return left_sum + query_sum(tree[vl].rCh, tree[vr].rCh, tm + 1, tr, k - left_count);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int k, l;
    cin >> k >> l;

    for (int i = 0; i < n; i++) a.push_back(a[i]), b.push_back(b[i]);

    vector<ll> prefA(2 * n + 1), prefB(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) prefA[i] = prefA[i - 1] + a[i - 1];
    for (int i = 1; i <= 2 * n; i++) prefB[i] = prefB[i - 1] + b[i - 1];

    for (int i = 0; i < 2 * n; i++) cout << a[i] << " "; cout << endl;
    for (int i = 0; i < 2 * n; i++) cout << b[i] << " "; cout << endl;

    ll ans = 0;
    sum_kth_smallest ST(b);

    for(int i = 0; i < 2 * n; ++i){
        cout << prefA[i] << " ";
    }
    cout << "\n";
    for(int i = 0; i < 2 * n; ++i){
        cout << prefB[i] << " ";
    }

    cout << "\n";



    for (int i = 1; i < n; i++) {
//        ll A = preA[i - 1] + preA[n] - preA[i + x - 1];
        ll A = prefA[i + k] - prefA[i];
        ll B = prefB[i + k] - prefB[i] - (k == l ? 0 : ST.query_sum(i, i + k - 1, k - l));
        cout << A << endl;
        cout << prefB[i + k] - prefB[i] << " " << (k == l ? 0 : ST.query_sum(i, i + k - 1, k - l)) << endl;
        ans = max(ans, A + B);
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // w(t) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        // tc++;
    // }

    return 0;
}
