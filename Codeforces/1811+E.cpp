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

ll getPower(ll b, ll e){

    ll ans = 1;

    while(e){
        ans *= b;
        --e;
    }

    return ans;
}


bool valid(ll x){

    while(x){
        if(x % 10 == 4){
            return 0;
        }

        x /= 10;
    }

    return 1;
}

ll toBase9(ll x){
    ll ans = 0;

    ll rem = 0;
    ll i = 1;

    while(x){
        rem = x % 9;
        ans += rem * i;
        x /= 9;
        i *= 10;
    }

    return ans;
}

string toStr(ll x){

    string s;

    while(x){
        s += ((x % 10)) + '0';

        if(s[s.size() - 1] > '3'){
            ++s[s.size() - 1];
        }
        x /= 10;
    }

    reverse(s.begin(), s.end());

    return s;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        cout << toStr(toBase9(n)) << "\n";
    }
    
    return 0;
}