// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    // fast();

    int n;
    cin >> n;

    vector <int> a(n);
    read(a, n);

    vector <int> b(n);
    read(b, n);

    map <int, int> mp1;
    map <int, int> mp2;

    for(int i = 0; i < n; ++i){
        mp1[a[i]] = i;
        mp2[b[i]] = i;
    }

    int ans = 1;

    int id = min(mp1[1], mp2[1]);
    ans += (id * (id + 1)) / 2;

    id = n - max(mp1[1], mp2[1]) - 1;
    ans += (id * (id + 1)) / 2;

    id = abs(mp1[1] - mp2[1]) - 1;
    ans += (id * (id + 1)) / 2;

    // cout << "Ans : " << ans << "\n";

    int mil = min(mp1[1], mp2[1]);
    int mir = max(mp2[1], mp2[1]);

    for(int i = 2; i <= n; ++i){
        
        int nil = min(mp1[i], mp2[i]);
        int nir = max(mp1[i], mp2[i]);

        // cout << i << " ->" << nil << " " << nir << " :: " << mil << " " << mir << " :: " << ans << " :::::: ";

        if(mil > nir){
            // Add to ans
            ++ans;
            // cout << "Added1 " << (mil - nir) * (n - mir - 1) << "\n";
            ans += (mil - nir) * (n - mir - 1);
        }

        if(mir < nil){
            // Add to ans
            ++ans;
            // cout << "Added2 " << (mil) * (nil - mir) << "\n";
            ans += (mil) * (nil - mir);
        }

        // cout << ans << "\n";

        mil = min(mil, nil);
        mir = max(mir, nir);
    }

    cout << ans << "\n";
    
    
    return 0;
}