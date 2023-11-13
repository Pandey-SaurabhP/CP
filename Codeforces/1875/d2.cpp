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

int main(){
    fast();

    ll t;
    cin >> t;

    while(t--){
        memset(dp, -1, sizeof(dp));

        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        map <ll, ll> mp;

        for(auto it : a){
            mp[it]++;
        }

        vector <int> nums(mp.size());
        vector <int> cnt(mp.size());

        int k = 0;

        for(auto it : mp){
            nums[k] = it.first;
            cnt[k] = it.second;
            ++k;
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

        int xyz = nums.size() - 1;
        for(int i = xyz; i >= 0; --i){
            if((cnt[i] - 1) * mex + nums[i]){

            }
        }


    }

    return 0;
}



