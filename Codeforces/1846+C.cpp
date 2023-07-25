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

bool cmp(pair <ll, pair <ll, ll>> a, pair <ll, pair <ll, ll>> b){

    if(a.second.first > b.second.first){
        return 1;
    }
    else if(a.second.first == b.second.first){
        if(a.second.second < b.second.second){
            return 1;
        }
    }

    return 0;
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, m, h;
        cin >> n >> m >> h;

        vector <vector <ll>> a(n, vector <ll> (m));

        for(ll i = 0; i < n; ++i){
            for(ll j = 0; j < m; ++j){
                cin >> a[i][j];
            }

            sort(a[i].begin(), a[i].end());
        }
        
        vector <ll> solveCnt(n, 0);
        vector <ll> penalty(n, 0);
        

        for(ll i = 0; i < n; ++i){

            ll passed = 0;

            for(ll j = 0; j < m; ++j){
                if(passed + a[i][j] <= h){

                    passed += a[i][j];
                    penalty[i] += passed;
                    ++solveCnt[i];
                }
                else{
                    break;
                }
            }
        }

        vector <pair <ll, pair <ll, ll>>> vc(n);

        for(ll i = 0; i < n; ++i){
            vc[i] = {i, {solveCnt[i], penalty[i]}};
        }

        sort(vc.begin(), vc.end(), cmp);


        // for(ll i = 0; i < n; ++i){
        //     cout << vc[i].first << " " << vc[i].second.first << " " << vc[i].second.second << "\n";
        // }

        // cout << "\n";

        for(ll i = 0; i < n; ++i){
            if(vc[i].first == 0){
                cout << i + 1 << "\n";
                break;
            }
        }

    }
    
    return 0;
}