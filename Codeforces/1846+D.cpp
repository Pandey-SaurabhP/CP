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

ld getArea(ld d, ld h){
    ld ans = 0.5 * d * h;
    return ans;
}

ld unitArea(ld d, ld h){
    ld ans = d / (2.0 * h);
    return ans;
}

ld coveredArea(ld d, ld h, ld c){
    ld ans = unitArea(d, h);
    ans *= (c * c);

    return ans;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;

        ld d, h;
        cin >> n >> d >> h;

        vector <ld> a(n);
        read(a, n);

        sort(a.begin(), a.end());

        ld ans = 0;

        for(int i = 0; i < n - 1; ++i){
            int stA = a[i];
            int edA = a[i] + h;

            int stB = a[i + 1];
            int edB = a[i + 1] + h;

            if(edA > stB){
                ld localAns = getArea(d, h);
                localAns -= coveredArea(d, h, edA - stB);
                ans += localAns;
            }
            else{
                ans += getArea(d, h);
            }

            // cout << i << " : " << ans << "\n";
        }

        ans += getArea(d, h);

        cout << fixed << setprecision(10) << ans << "\n";

        

    }
    
    return 0;
}