
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

    int n, r;
    cin >> n >> r;

    vector <int> a(n);
    read(a, n);

    int cnt = 0;

    for(int i = 0; i < n; ++i){
        if(a[i] <= r){
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}




