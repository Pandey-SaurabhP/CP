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

vector <ll> ans;
map <ll, ll> mp;

map <ll, bool> dp;
vector <ll> fct;

bool isTwoPower(ll x){
    ll a = 1;

    while(a <= x){
        if(a == x) return 1;
        a *= 2;
    }

    return 0;
}

bool solve(ll x, ll oneCnt){
    if(x == 1){
        cout << ans.size() << "\n";
        print(ans, ans.size());
        return 1;
    }

    if(oneCnt == 2) return 0;

    fct.clear();
    fct.push_back(1);
    for(ll i = 2; i * i <= x; ++i){
        if(x % i == 0){
            if(i == (x / i)){
                fct.push_back(i);
            }
            else{
                fct.push_back(i);
                fct.push_back(x / i);
            }
        }
    }

    sort(fct.begin(), fct.end());
    reverse(fct.begin(), fct.end());

    for(auto it : fct){
        if(isTwoPower(x - it)){
            ans.push_back(x - it);
            if(solve(x - it, (oneCnt + (it == 1)))){
                return 1;
            }
            ans.pop_back();
        }
    }

    for(auto it : fct){
        mp[it]++;
        ans.push_back(x - it);

        if(mp[it] <= 2){
            if(solve(x - it, oneCnt + (it == 1))){
                return 1;
            }
        }

        ans.pop_back();
        mp[it]--;
    }

    return 0;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        mp.clear();
        ans.clear();
        ll x;
        cin >> x;

        ans.push_back(x);

        solve(x, 0);
    }

    return 0;
}
