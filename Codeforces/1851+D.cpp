#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <ll> a(200005), b(200005);

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        read(a, n - 1);

        ll sm = (n * (n + 1ll)) / 2ll;

        if(a[n - 2] == sm){
    
            b[0] = a[0];

            for(ll i = 1; i < n - 1; ++i){
                b[i] = a[i] - a[i - 1];
            } 

            // Try if any element > n
            vector <bool> done(n + 5, 0);

            for(ll i = 0; i < n - 1; ++i){
                if(b[i] <= n) done[b[i]] = 1;
            }

            set <ll> notDone;
            for(ll i = 1; i <= n; ++i){
                if(!done[i]){
                    notDone.insert(i);
                }
            }

            if(notDone.size() != 2){
                cout << "NO\n";
                continue;
            }

            bool ok = 0;

            set <ll> mp;

            for(ll i = 0; i < n - 1; ++i){
                
                if(b[i] > n || mp.count(b[i])){
                    // This element will be broken
                    ll x, y;
                    x = y = -1;
                    for(auto it : notDone){
                        if(x != -1){
                            y = it;
                        }
                        else{
                            x = it;
                        }
                    }

                    if(x + y == b[i]){
                        ok = 1;
                        break;
                    }
                    else break;
                }

                if(!mp.count(b[i])){
                    mp.insert(b[i]);
                }
            }

            if(ok){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else if(a[n - 2] < sm){
            a[n - 1] = sm;

            vector <bool> done(n + 1, 0);
            if(a[0] <= n) done[a[0]] = 1;

            for(ll i = 1; i < n; ++i){
                if(a[i] - a[i - 1] <= n) done[a[i] - a[i - 1]] = 1;
            }

            bool ok = 1;
            for(ll i = 1; i <= n; ++i){
                if(!done[i]){
                    ok = 0;
                    break;
                }
            }

            if(ok){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}