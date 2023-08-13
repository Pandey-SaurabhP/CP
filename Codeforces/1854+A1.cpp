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

bool allNegative(vector <int> &a, int n){
    for(auto it : a){
        if(it > 0) return 0;
    }

    return 1;
}
int main(){

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        read(a, n);

        if(allNegative(a, n)){
            cout << n - 1 << "\n";
            for(int i = n - 2; i >= 0; --i){
                cout << i + 1 << " " << i + 2 << "\n";
            }
            continue;
        }

        int mxId = 0;
        for(int i = 0; i < n; ++i){
            if(a[mxId] < a[i]){
                mxId = i;
            }
        }

        vector <pair <int, int>> vc;

        for(int i = 0; i < 5; ++i){
            vc.push_back({mxId + 1, mxId + 1});
            a[mxId] += a[mxId];
        }

        for(int i = 0; i < n; ++i){
            if(i != mxId){
                vc.push_back({i + 1, mxId + 1});
                a[i] += a[mxId];
            }
        }

        // print(a, n);

        for(int i = 1; i < n; ++i){
            a[i] += a[i - 1];
            vc.push_back({i + 1, i});
        }

        cout << vc.size() << "\n";

        for(auto it : vc){
            cout << it.first << " " << it.second << "\n"; 
        }

        // print(a, n);
    }
    
    return 0;
}