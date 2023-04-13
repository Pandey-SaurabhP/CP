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

string toStr(ll x){
    string ans;

    while(x){
        ans += (x % 10) + '0';
        x /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

ll memo[22][2][12][12][2][2][2];

string tmp;

ll solve(ll i, bool tight, char l, char sl, bool e, bool o, bool started, string &a){

    if(i == a.size()){
        if(started & (e & o)){
            cout << tmp << "\n";
            return 1;
        }
        return 0;
    }

    if(memo[i][tight][l][sl][e][o][started] != -1){
        return memo[i][tight][l][sl][e][o][started];
    }

    ll ans = 0;

    if(tight){
        
    }
    else{

    }

    return memo[i][tight][l - '0'][sl - '0'][e][o][started] = ans;
}

int main(){

    // fast();
    memset(memo, -1, sizeof(memo));

    ll t;
    cin >> t;

    while(t--){
        ll a, b;
        cin >> a >> b;

        string sa, sb;

        sa = toStr(a);
        sb = toStr(b);

        ll aa = solve(0, 1, '9' + 1, '9' + 2, 0, 0, 0, sa);
        ll bb = solve(0, 1, '9' + 1, '9' + 2, 0, 0, 0, sb);

        // cout << aa << " " << bb << "\n";

        cout << bb - aa << "\n";

    }
    
    return 0;
}