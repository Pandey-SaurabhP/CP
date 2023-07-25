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

bool isPerm(vector <int> a, int n){
    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i){
        if(a[i] != i + 1){
            return 0;
        }
    }

    return 1;
}

int fact(int n){

    int ans = 1;
    for(int i = 1; i <= n; ++i){
        ans *= i;
    }

    return ans;
}

bool func(vector <int> a, int n){

    vector <int> b(n);
    b[0] = a[0];

    for(int j = 1; j < n; ++j){
        b[j] = b[j - 1] + a[j];
    }

    for(int j = 0; j < n; ++j){
        b[j] %= n;
        ++b[j];
    }

    print(b, n);

    return isPerm(b, n);
}

int main(){

    // fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);

        // a = {1,2,3,4,5,6,7,8,9,10,11,12};

        a[0] = n;

        int l = 1;
        int r = n - 1;

        for(int i = 1; i < n / 2; ++i){
            a[i] = l;
            a[n - i] = r;

            ++l;
            --r;
        }

        a[n / 2] = n / 2;

        a = {10, 1, 3, 2, 4, 5, 6, 8, 7, 9};
        
        print(a, n);

        if(func(a, n)){
            cout << "Hell!\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}