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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int zc = 0;
        int oc = 0;

        for(int i = 0; i < n; ++i){
            if(s[i] == '0'){
                zc++;
            }
            else{
                oc++;
            }
        }

        int k = min(zc, oc);

        if(k % 2 == 0){
            cout << "Ramos\n";
        }
        else{
            cout << "Zlatan\n";
        }
    }
    
    return 0;
}