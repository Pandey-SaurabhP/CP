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

bool eve(vector <int> &a, int n){
    for(auto it : a){
        if(it % 2 == 1){
            return 0;
        }
    }
    return 1;
}

bool odd(vector <int> &a, int n){

    int mn = INT_MAX;

    for(auto it : a){
        if(it % 2 == 1) mn = min(it, mn);
    }

    for(auto it : a){
        if(it % 2 == 0){
            it -= mn;

            if(it <= 0) return 0;
        }
    }

    return 1;

}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        bool a1 = eve(a, n);
        bool a2 = odd(a, n);

        if(a1 | a2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}