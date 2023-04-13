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
        ll n;
        cin >> n;

        vector <ll> a(n);
        read(a, n);

        priority_queue <ll> pq;

        ll ans = 0;

        for(ll i = 0; i < n; ++i){

            if(a[i] == 0){
                
                if(!pq.empty()){

                    ans += pq.top();
                    pq.pop();
                }
            }
            else{
                pq.push(a[i]);
            }
        }

        cout << ans << "\n";
    }
    
    return 0;
}