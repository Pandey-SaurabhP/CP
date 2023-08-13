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

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        string x;
        cin >> x;

        int n = x.size();

        if(x[0] >= '5'){
            string ans = "";
            while(ans.size() != x.size()){
                ans += '0';
            }
            ans += '1';
            reverse(ans.begin(), ans.end());
            cout << ans <<"\n";
            continue;
        }

        int lastId = -1;

        for(int i = n - 1; i > 0; --i){
            if(x[i] >= '5'){
                x[i] = '0';
                lastId = i;
                if(x[i - 1] != '9'){
                    x[i - 1] = x[i - 1] + 1; 
                }
            }
        }

        if(lastId != -1){
            for(int i = lastId; i < n; ++i){
                x[i] = '0';
            }
        }

        if(x[0] >= '5'){
            string ans = "";
            while(ans.size() != x.size()){
                ans += '0';
            }
            ans += '1';
            reverse(ans.begin(), ans.end());
            cout << ans <<"\n";
            continue;
        }

        cout << x << "\n";
    }
    
    return 0;
}