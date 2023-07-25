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

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        int start = 0;

        int mxOpen = 0;

        for(int i = 0; i < n; ++i){
            
            int j = i;
            while(j < n && s[j] == '<'){
                ++j;
            }

            mxOpen = max(mxOpen, j - i);
        }

        int mxClose = 0;

        for(int i = 0; i < n; ++i){
            
            int j = i;
            while(j < n && s[j] == '>'){
                ++j;
            }

            mxClose = max(mxClose, j - i);
        }

        cout << max(mxOpen, mxClose) + 1 << "\n";
        
    }
    
    return 0;
}