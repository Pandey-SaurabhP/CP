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

ll dp[5006][5006];

ll solve(ll j, ll mex, vector <ll> &num, vector <ll> &cnt){
    if(mex == 0){
        return 0;
    }

    if(j < 0){
        return INT_MAX;
    }

    if(dp[j][mex] != -1){
        return dp[j][mex];
    }



    ll ans = INT_MAX;

    ans = min(ans, ((cnt[j] - 1) * mex + num[j]) + solve(j - 1, min(mex, num[j]), num, cnt));
    ans = min(ans, solve(j - 1, mex, num, cnt));

    return dp[j][mex] = ans;
}

int main(){
    fast();

    ll t;
    cin >> t;

    while(t--){

        ll n;
        cin >> n;

        for(int i = 0; i < n + 5; ++i){
            for(int j = 0; j < n + 5; ++j){
                dp[i][j] = -1;
            }
        }

        vector <ll> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        map <ll, ll> mp;

        for(auto it : a){
            mp[it]++;
        }

        vector <ll> num(mp.size());
        vector <ll> cnt(mp.size());

        ll x = 0;
        for(auto it : mp){
            num[x] = it.first;
            cnt[x] = it.second;

            ++x;
        }


        ll mex = a[n - 1] + 1  ;
        ll st = 0;
        for(ll i = 0; i < n; ++i){
            if(a[i] != st){
                mex = st;
                break;
            }
            else{
                while(a[i] == st){
                    ++i;
                }
                --i;
                ++st;
            }
        }

        ll xyz = num.size() - 1;
        cout << solve(xyz, mex, num, cnt) << "\n";
    }

    return 0;
}



