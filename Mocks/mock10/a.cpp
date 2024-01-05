
#include <bits/stdc++.h>

using namespace std;

#define endl        '\n'
#define pb          push_back
#define pf          push_front
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

int n, q;
vector<string> v;

int lengthOfLIS(vector<string>& nums) {
    string s;
    for (auto &i : nums) s += i;
    vector<int> dp(s.size()), hash(s.size());

    int imax = 0;
    for (int i = 0; i < s.size(); i++) {
        dp[i] = 1;
        hash[i] = i;
        for (int j = 0; j < i; j++) {
            if (s[j] <= s[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                if (1 + dp[j] >= dp[i]) hash[i] = j;
            }
        }
        if (dp[i] >= dp[imax]) imax = i;
    }

    return dp[imax];
}

void dfs(int mask, vector<string> &s) {
    if (mask == q) {
        int len = lengthOfLIS(s);
        if (len == 9) {
            cout << "TEST:\n";
            for (auto &x : s) cout << x << " "; cout << endl;
            cout << len << endl;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        // if (!(mask & (1 << i))) {
            s.push_back(v[i]);
            dfs(mask + 1, s);
            s.pop_back();
        // }
    }
}

void solve() {
    cin >> n >> q;

    v.resize(n);
    for (auto &i : v) cin >> i;

    vector<string> s;
    dfs(0, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    w(t) {
        // cout<<"Case #"<<tc<<": ";
        solve();
        tc++;
    }

    return 0;
}	

// q 


// zhkb kxks vx x


// vgxg vgxg 
