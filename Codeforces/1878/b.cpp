#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void initCode(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

vector <bool> isPrime(mxn, 1);
vector <int> primeList;

void sieve(){
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < mxn; ++i){
        if(isPrime[i]){
            for(int j = i * i; j < mxn; j += i){
                isPrime[j] = 0;
            }
        }
    }

    for(int i = 2; i < mxn; ++i){
        if(i != 3 && isPrime[i]){
            cout << i << " ";
            primeList.push_back(i);
        }
    }
}


int main(){
//    initCode();

    // fast();

//    sieve();
//
//    cout << "Hello\n";
//    cout << primeList.size() << "\n";

    ll t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int st = 5;
        int cnt = 0;

        while(cnt < n){
            cout << st << " ";
            st += 2;
            ++cnt;
        }

        cout << "\n";

    }

    return 0;
}

