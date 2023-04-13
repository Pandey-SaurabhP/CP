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
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        string fn;
        bool done = 0;

        for(int i = 0; i < n; ++i){
            if((s[i] - '0') < m && !done){
                fn += (m + '0');
                done = 1;
            }

            fn += s[i];
        }

        if(!done){
            fn += (m + '0');
        }

        cout << fn << "\n";
    }
    
    return 0;
}