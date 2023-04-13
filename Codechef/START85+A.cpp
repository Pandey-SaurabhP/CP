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

    fast();

    int t;
    cin >> t;

    while(t--){
        string n;
        cin >> n;

        int x = n.size();
        if(x == 1){
            cout << n << "\n";
        }
        else{
            int lst2 = ((n[n.size() - 2] - '0') * 10) + (n[n.size() - 1] - '0');
            // cout << lst2 << "\n";
            cout << lst2 % 20 << "\n";
        }
    }
    
    return 0;
}