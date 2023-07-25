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

bool check(vector <ll> &a, ll n, ll c, ll d, ll mid){

    ll curSum = 0;
    ll i = 0;
    ll daysGone = 0;
    ll gap = 0;

    while(1){ 
        
        if(i < n) curSum += a[i];
        ++daysGone;

        if(daysGone >= d){
            break;
        }

        if(gap == mid){
            i = 0;
            gap = 0;
            continue;
        }

        ++gap;
        ++i;
    }

    if(curSum >= c) return 1;
    return 0;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, c, d;
        cin >> n >> c >> d;

        vector <ll> a(n);

        read(a, n);
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        ll sm = 0ll;
        for(int i = 0; i < min(d, n); ++i){
            sm += a[i];
        }

        if(a[0] * d < c){
            cout << "Impossible\n";
        }
        else if(sm >= c){
            cout << "Infinity\n";
        }
        else{

            ll ans = 0;

            ll l = 0;
            ll h = 1000000000000000000;

            while(l < h){
                ll mid = (l + h) / 2;

                if(check(a, n, c, d, mid)){
                    ans = mid;
                    l = mid + 1;
                }
                else{
                    h = mid;
                }
            }

            cout << ans << "\n";
        }

    }
    
    return 0;
}