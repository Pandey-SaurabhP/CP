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

        vector <int> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        vector <int> b, c;

        int i = 0;
        while(i < n && a[i] == a[0]){
            b.push_back(a[i]);
            ++i;
        }

        while(i < n){
            c.push_back(a[i]);
            ++i;
        }

        if(c.size() == 0){
            cout << -1 << "\n";
        }
        else{
            cout << b.size() << " " << c.size() << "\n";
            print(b, b.size());
            print(c, c.size());
        }
    }
    
    return 0;
}