// pandeyGRocks
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;

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

        bool fndAnswer = 0;
        vector <int> pf;

        for(int i = 2; i * i <= n; ++i){

            if(n % i == 0){

                if(i != n / i){
                    cout << 1 << " " << i  << " " << n / i << "\n";
                    fndAnswer = 1;
                    break;
                }
            }
        }

        if(!fndAnswer){
            cout << "-1\n";
        }
    }
    
    return 0;
}