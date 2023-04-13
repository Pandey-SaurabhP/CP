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

vector <vector <int>> multiply(vector <vector <int>> a, vector <vector <int>> b){

    vector <vector <int>> c(2, vector <int> (2));

    c[0][0] = a[0][0] * b[0][0] + a[1][0] * b[0][1];
    c[0][1] = a[0][0] * b[1][0] + a[1][0] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[0][1];
    c[1][1] = a[1][0] * b[1][0] + a[1][1] * b[1][1];

    return c;
}

vector <vector <int>> fastPower(int x){

    vector <vector <int>> unit = {{1, 1}, {1, 0}};
    vector <vector <int>> ans = unit;

    while(x){

        if(x & 1){
            ans = multiply(ans, unit);
            --x;
        }

        unit = multiply(unit, unit);
        x /= 2;
    }

    return ans;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        cout << fastPower(n - 1)[0][0] << "\n";
    }
    
    return 0;
}