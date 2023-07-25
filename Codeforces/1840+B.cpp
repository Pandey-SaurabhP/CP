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

vector <int> a(35, 1);
for(int i = 1; i < 36; ++i){
    a[i] = pow(2, i);
}


int solve(int i, int n, int sm){
    if(i == n){
        return (sm >= 0);
    }

    int ans = 0;

    ans += solve(i + 1, n, sm);
    ans += a[i] + solve(i + 1, n, sm);

    return ans;
}




int main(){

    // fast();

    

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        
        cout << solve(0, k, n);
    }
    
    return 0;
}