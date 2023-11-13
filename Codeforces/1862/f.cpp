
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

map <pair <int, int>, int> dp;

bool solve(int i, vector <int> &a, int &n, int mw, int mf){
    if(i == n) return 1;

    if(a[i] > mw && a[i] > mf) return 0;

    if(dp.count({i, mw})){
        return dp[{i, mw}];
    }

    if(a[i] <= mw && a[i] <= mf){
        bool a1 = solve(i + 1, a, n, mw - a[i], mf);
        bool a2 = solve(i + 1, a, n, mw, mf - a[i]);

        return dp[{i, mw}] = a1 | a2;
    }
    else if(a[i] <= mw){
        bool a1 = solve(i + 1, a, n, mw - a[i], mf);
        return dp[{i, mw}] = a1;
    }
    else if(a[i] <= mf){
        bool a2 = solve(i + 1, a, n, mw, mf - a[i]);
        return dp[{i, mw}] = a2;
    }
}

bool ok(vector <int> &a, int n, int mid, int ww, int ff){

    dp.clear();

    return solve(0, a, n, ww * mid, ff * mid);
}

int main(){

     fast();

    ll t;
    cin >> t;

    while(t--){
        int w, f;
        cin >> w >> f;

        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        int lo = 0, hi = 100;

        int ans = 100;

        while(lo < hi){
            int mid = (lo + hi) / 2;
//            cout << mid << "\n";

            if(ok(a, n, mid, w, f)){
                ans = mid;
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}

