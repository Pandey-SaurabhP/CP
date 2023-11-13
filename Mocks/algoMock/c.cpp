
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + v[i - 1];

    vector<ll> ppref(n + 2, 0);
    for (int i = 1; i <= n + 1; i++) ppref[i] = ppref[i - 1] + pref[i - 1];
//
//     for (auto &i : pref) cout << i << " "; cout << endl;
//     for (auto &i : ppref) cout << i << " "; cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        k = min(k, r - l + 1);

        ll ans = ppref[r + 1] - ppref[l + k - 1];
        ans -= ppref[r - k + 1] - ppref[l - 1];

//        cout << r - l + 1 - k + 1 << "\n";

        ll x = (k - 1) * pref[r] - ppref[r] + ppref[r - k + 1];
        ans += x;

        cout << ans << endl;
    }


}

int main(){


    solve();

    return 0;
}

//1 2 3 4 5 6
//0 1 3 6 10 15 21
//0 1 4 10 20 35 56

//1 4 4
//20 - 10 - 0 = 10



//
//2 + 3 + 3 + 4 + 4 + 5 + 5 + 6

//6 - 1 + 10 - 3 + 15 - 6 + 21 - 10
//(6 + 10 + 15 + 21) - (1 + 3 + 6 + 10)
//52 - 20 = 32

// a1 a2 a3 a4 a5 a6

//1 6 4

//a4 + a5 + a6
//a5 + a6
//a6

//p6 - p3
//p6 - p4
//p6 - p5
//
//3 * p6 - (p3 + p4 + p5)
//(k - 1)


//
// 2 5 3

//(a2 + a3 + a4) + a3 + a4 + a5
// p4 - p1  +  p5 - p2
//(p4 + p5) - (p1 + p2)
//
// pp5 - pp3 - pp2


//
// (a2 + a3)  + (a3 + a4) + (a4 + a5) + (a5 + a6)
// (p3 - p1) + (p4 - p2) + (p5 - p3) + (p6 - p4)
// (p3 + p4 + p5 + p6) - (p1 + p2 + p3 + p4)


