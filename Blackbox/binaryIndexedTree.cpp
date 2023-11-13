#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

vector <int> bit(mxn, 0);

void build(vector <int> &a, int &n){

    for(int i = 0; i < n; ++i){
        int j = i + 1;

        while(j <= n){
            bit[j - 1] += a[i];
            j += j & -j;
        }
    }
}

void update(int i, int v, vector <int> &a, int &n){

    int j = i + 1;

    int old = a[i];

    while(j <= n){
        bit[j - 1] -= old;
        bit[j - 1] += v;

        j += j & -j;
    }

    a[i] = v;
}


int getSum(int r){

    int ans = 0;

    ++r;

    while(r >= 1){
        ans += bit[r - 1];

        r -= r & -r;
    }

    return ans;
}

int main() {

//    00000
//    10000


    int n;
    cin >> n;

    vector <int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    build(a, n);
    print(bit, i, n);

    update(2, 7, a, n);
    print(bit, i, n);

    cout << getSum(4);

    return 0;
}

