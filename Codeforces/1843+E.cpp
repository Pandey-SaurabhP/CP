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

bool check(vector <pair <int, int>> &vc, int &m, vector <int> &id, int &q, int &n, int mid){

    vector <int> a(n, 0);

    for(int i = 0; i <= mid; ++i){
        a[id[i]] = 1;
    }

    vector <int> pre(n, 0);
    pre[0] = a[0];

    for(int i = 1; i < n; ++i){
        pre[i] = pre[i - 1] + a[i];
    }

    // cout << "Pre : ";
    // print(pre, n);
    // cout << " ::: " << mid << "\n";

    int zero, one;

    for(int i = 0; i < m; ++i){
        int l = vc[i].first;
        int r = vc[i].second;

        if(l == 0){
            one = pre[r];
        }
        else{
            one = pre[r] - pre[l - 1];
        }

        int sz = r - l + 1;
        zero = sz - one;

        if(one > zero){
            // cout << "OK \n";
            return 1;
        }
    }

    // cout << "Not\n";
    return 0;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int m, n;
        cin >> n >> m;

        vector <pair <int, int>> vc(m);

        for(int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;

            --x; --y;

            vc[i] = {x, y};
        }

        int q;
        cin >> q;
        vector <int> id(q);

        read(id, q);
        for(int i = 0; i < q; ++i){
            id[i]--;
        }

        int ans = INT_MAX;

        int lo = 0;
        int hi = q - 1;

        while(lo <= hi){

            int mid = (lo + hi) / 2;

            // cout << mid << " ";

            if(check(vc, m, id, q, n, mid)){ // All inclusive
                ans = mid + 1;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        if(ans == INT_MAX){
            cout << -1 << "\n";
        }
        else{
            cout << ans << "\n";
        }
    }
    
    return 0;
}