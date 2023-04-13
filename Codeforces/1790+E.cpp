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

int main(){

    // fast();

    ll t;
    cin >> t;

    while(t--){
        ll x;
        cin >> x;

        ll sumReq = x;

        

        vector <ll> nums;
        ll p = 1, tmp = x;

        while(p != 33){
            if(!(tmp & 1)){
                nums.push_back(1ll << p);
            }

            tmp >>= 1;
            ++p;
        }

        // Can the required number be represented as sum of numbers
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        ll b = 0;
        ll a = x;

        for(int i = 0; i < nums.size(); ++i){
            if(sumReq >= nums[i]){
                sumReq -= nums[i];
                b += nums[i] >> 1ll;
                a += nums[i] >> 1ll;
            }
        }

        if(sumReq == 0){
            cout << a << " " << b << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
    
    return 0;
}