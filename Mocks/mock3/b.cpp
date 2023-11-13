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


vector <int> sum(mxn, 0);

int main(){

    fast();

    for(int i = 1; i < mxn; ++i){
        for(int j = i + i; j < mxn; j += i){
            sum[j] += i;
        }
    }

    int t;
    cin >> t;

    for(int i= 0; i < t; ++i){
        int x;
        cin >> x;

        if(sum[x] == x){
            cout << "perfect\n";
        }
        else if(sum[x] > x){
            cout << "abundant\n";
        }
        else{
            cout << "deficient\n";
        }
    }


    return 0;
}

