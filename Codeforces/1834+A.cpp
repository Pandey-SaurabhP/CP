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

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        int negCnt = 0;
        int posCnt = 0;

        int ans = 0;

        for(auto it : a){
            if(it > 0) posCnt++;
            else negCnt++;
        }

        if(negCnt % 2 == 1){
            --negCnt;
            ++posCnt;

            ++ans;
        }

        if(negCnt > posCnt){
            int change = (negCnt - posCnt + 1) / 2;
            negCnt -= change;
            posCnt += change;
            ans += change;
        }

        if(negCnt % 2 == 1){
            ++ans;
            --negCnt;
            ++posCnt;
        }

        cout << ans << "\n";
    }
    
    return 0;
}