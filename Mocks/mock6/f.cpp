
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
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

    int n;
    cin >> n;

    vector <int> a(n);
    read(a, n);

    vector <int> b(n);
    read(b, n);

    int k, l;
    cin >> k >> l;

    vector <int> preA(n + 1, 0);
    for(int i = 0; i < n; ++i){
        preA[i + 1] = preA[i] + a[i];
    }

    print(preA, n + 1);

    int x = n - k;

    for(int i = 1; i + x - 1 <= n; ++i){
        int frontSum = preA[i - 1] + preA[n] - preA[i + x - 1];

        cout << i << " " << i + x - 1 << " : " << frontSum << "\n";
    }





    return 0;
}
