#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main(){

    fast();

    int a, x, b, y, t;
    cin >> a >> x >> b >> y >> t;

    int a1 = a + (21 * max(0, t - 30) * x);
    int a2 = b + (21 * max(0, t - 45) * y);

    cout << a1 << " " << a2 << "\n";

    return 0;
}





