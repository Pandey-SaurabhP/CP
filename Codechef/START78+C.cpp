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
        ll n, k;
        cin >> n >> k;

        vector <ll> a(n);
        vector <ll> b(n);

        read(a, n);
        read(b, n);

        vector <pair <ll, ll>> s(n);

        for(ll i = 0; i < n; ++i){
            s[i] = {a[i] + b[i], i};
        }

        sort(s.begin(), s.end());

        ll sm = 0;
        ll cnt = 0;

        vector <bool> done(n, 0);

        ll id = -1;

// We have some fully solved problems
        for(ll i = 0; i < n; ++i){

            if(sm + s[i].first > k){
                id = i;
                break;
            }

            sm += s[i].first;
            ++cnt;
            done[s[i].second] = 1;
        }

// Choose a partially solve problem from the set
        bool fnd = 0;

        for(ll j = 0; j < n; ++j){
            if(!done[j]){
                if(sm + a[j] <= k){
                    ++cnt;
                    done[j] = 1;
                    fnd = 1;
                    break;
                }
            }
        }

// Choosing last element completely then a secondary element partially
        if(!fnd && id != -1){

            sm += s[id].first;
            done[s[id].second] = 1;

            for(ll i = 0; i < n; ++i){
                if(done[i]){
                    if(sm - b[i] <= k){
                        ++cnt;
                        break;
                    }
                }
            }

            cout << cnt << "\n";
        }
        else{
            cout << cnt << "\n";
        }
    }
    
    return 0;
}