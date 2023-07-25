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

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll m, n;
        cin >> m >> n;

        if(n > m){
            cout << "NO\n";
            continue;
        }

        vector <ll> op;
        op.push_back(m);

        while(m % 2 == 0){
            op.push_back(m / 2);
            m/= 2;
        }

        // print(op, op.size());

        vector <ll> cp(op.size());
        ll x = 1;

        for(ll i = 0; i < op.size(); ++i){
            cp[i] = x;
            x *= 2;
        }

        ll rq = n;
        ll div = 1;

        for(ll i = 0; i < op.size(); ++i){

            if(rq >= op[i]){

                cp[i] /= div;

                ll mx = rq / op[i];

                rq -= min(mx * op[i], op[i] * cp[i]);
                div *= 2;
            }

            // cout << i << " : " << rq << "\n";
        }

        if(rq == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}