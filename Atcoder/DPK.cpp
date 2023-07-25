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

bool solve(int k, bool turn, vector <int> &a, int &n){
    if(k == 0){
        return (turn == 1);
    }

    if(k < 0){
        return 0;
    }

    bool ok = 0;
    for(int i = 0; i < n; ++i){
        ok |= solve(k - a[i], turn ^ 1, a, n);
    }

    return ok;
}

int main(){

    // fast();

    int n, k;
    cin >> n >> k;

    vector <int> a(n);
    read(a, n);

    cout << solve(k, a, n);
    
    return 0;
}