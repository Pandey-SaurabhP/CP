// pandeyGRocks // WA/TLE
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

vector <ll> fib(46);

vector <ll> smEven;
vector <ll> smOdd;

void fillInEven(ll i, ll smE){

    if(i >= 46){
        return;
    }

    smEven.push_back(smE);

    fillInEven(i + 2, smE + fib[i]);
    fillInEven(i + 2, smE);
    
}

void fillInOdd(ll i, ll smO){
    if(i >= 46){
        return;
    }

    smOdd.push_back(smO);

    fillInOdd(i + 2, smO + fib[i]);
    fillInOdd(i + 2, smO);   
}

bool isPossible(bool useEven, ll sm){
    if(useEven){
        if(binary_search(smEven.begin(), smEven.end(), sm)){
            return 1;
        }

        return 0;
    }
    else{
        if(binary_search(smOdd.begin(), smOdd.end(), sm)){
            return 1;
        }

        return 0;
    }
}

int main(){

    fast();

    fib[0] = 1;
    fib[1] = 2;

    for(ll i = 2; i < 46; ++i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    fillInEven(0, 0);
    fillInOdd(1, 0);

    sort(smEven.begin(), smEven.end());
    sort(smOdd.begin(), smOdd.end());

    cout << smEven.size() << " " << smOdd.size() << "\n";

    ll t;
    cin >> t;

    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;

        ll l = b - 1;
        ll t = a - 1;

        if(n % 2 == 1){
            // Use only those at even index for l
            if(isPossible(1, l) & isPossible(0, t)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            // Use those at odd index for l
            if(isPossible(0, l) & isPossible(1, t)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
    
    return 0;
}