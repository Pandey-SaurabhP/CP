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
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << "";} cout << "\n";

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

string slv(string s, int n){
    s = '$' + s + '^';

    vector <int> p(n + 2, 1);

    // cout << s << "\n";

    int l = 1, r = 1;

    for(int i = 1; i <= n; ++i){

        p[i] = max(0, min(r - i, p[l + r - i]));

        while(s[i - p[i]] == s[i + p[i]]){
            ++p[i];
        }

        if(i + p[i] > r){
            l = i - p[i];
            r = i + p[i];
        }
    }

    int mxId = 0;

    for(int i = 0; i <= n + 1; ++i){
        if(p[i] > p[mxId]){
            mxId = i;
        }
    }

    string res = "";

    for(int i = mxId - p[mxId] + 1; i <= mxId + p[mxId] - 1; ++i){
        if(s[i] >= 'a' && s[i] <= 'z') res += s[i];
    }

    return res;
}

void solve() {
    string s;
    cin >> s;

    string ns = "#";

    for(int i = 0; i < s.size(); ++i){
        ns += s[i];
        ns += "#";
    }

    cout << slv(ns, ns.size());

}

int main(){
    
    fast();
    solve();

    return 0;
}