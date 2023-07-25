// pandeyGRocks
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

ll getSum(ll l, ll r){
    // Sum of 1 to r - sum of 1 to l - 1

    ll sm1 = r * (r + 1) * ((2 * r) + 1);
    sm1 /= 6;
    
    --l;

    ll sm2 = l * (l + 1) * ((2 * l) + 1);
    sm2 /= 6;

    return sm1 - sm2;
}

int main(){

    // fast();

    vector <ll> rowNum(mxn, 0);

    ll sm = 1;
    ll cnt = 1;
    ll rn = 1;
    
    for(ll i = 1; i < mxn; ++i){
        if(i == sm + 1){
            ++cnt;
            sm += cnt;

            ++rn;
        }

        rowNum[i] = rn;
    }


    vector <ll> st(2025), ed(2025);
    ll stt = 1;
    ll jump = 1;

    for(ll i = 1; i < 2025; ++i){
        st[i] = stt;
        stt += jump;
        ++jump;

        ed[i] = st[i] + i - 1;
    }

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        if(n == 1){
            cout << 1 << "\n";
            continue;
        }

        ll ans = 0;

        ans += n * n;

        ll l = max(n - rowNum[n], st[rowNum[n] - 1]);
        ll r = min(n - rowNum[n] + 1, ed[rowNum[n] - 1]);

        ll rn = rowNum[n] - 1;

        while(rn >= 0){
            ans += getSum(l, r);
            // cout << rn << " " << l << " " << r << " : " << getSum(l, r) << "\n"; 

            l = max(l - rowNum[l], st[rowNum[l] - 1]);
            r = min(r - rowNum[r] + 1, ed[rowNum[r] - 1]);

            
                        
            --rn;
        }

        cout << ans << "\n";
    }
    
    return 0;
}