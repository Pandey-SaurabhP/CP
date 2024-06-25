#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 1e6 + 5;
const int mod = 1e9 + 7;
const ll oo = 1e18;
int n, k;
int a[maxN];
void ReadInput()
{
    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> a[i];
}
void Solve()
{
    map<int, vector<int>> mp;
    for(int i=1; i<=n; i++)
        mp[a[i] % k].pb(a[i]);
    int res = 0;
    int cnt = 0;
    for(auto v : mp)
    {
        vector<int> vc = v.se;
        sort(vc.begin(), vc.end());
        if(vc.size() & 1)
        {
            cnt++;
            int val = oo;
            int s = 0;
            map<int, int> f1, f2;
            for(int i=0; i<vc.size()-1; i+=2)
            {
                s += (vc[i + 1] - vc[i]) / k;
                f1[i + 1] = s;
            }
            val = s;
            s = 0;
            for(int i=vc.size()-1; i>=1; i-=2)
            {
                s += (vc[i] - vc[i - 1]) / k;
                f2[i - 1] = s;
            }
            for(int i=2; i<vc.size()-1; i+=2)
                val = min(val, f1[i - 1] + f2[i + 1]);
            val = min(val, s);
            if(v.fi == 1)
            {
               // cout << f2[3];return;
            }
            res += val;
        }
        else
        {
            for(int i=0; i<vc.size(); i+=2)
                res += (vc[i + 1] - vc[i]) / k;
        }

    }
    if(cnt > 1)
    {
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n';
}
#define taskname "sol"
int32_t main()
{
    if (fopen(taskname ".inp", "r"))
    {
        freopen(taskname ".inp", "r", stdin);
        // freopen(taskname ".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for(int itest=1; itest<=T; itest++)
    {
        ReadInput();
        Solve();
    }
}
