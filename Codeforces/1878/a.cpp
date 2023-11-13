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

void initCode(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}


int main(){
    initCode();

    fast();

    ll t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        read(v, n);

        bool ok = 0;

        for(int i = 0; i < n; ++i){
            if(v[i] == k){
                ok = 1;
                break;
            }
        }

        if(ok){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}

