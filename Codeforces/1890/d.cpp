#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 2e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector <ll> par(mxn);
vector <ll> sz(mxn);
vector <ll> a(mxn);
vector <ll> wt(mxn);

ll getRoot(ll x){
    while(x != par[x]){
        par[x] = par[par[x]];
        x = par[x];
    }

    return x;
}
void union_(ll x, ll y){
    ll xr = getRoot(x);
    ll yr = getRoot(y);

    if(xr == yr) return;

    if(sz[xr] >= sz[yr]){
        par[yr] = xr;
        sz[xr] += sz[yr];
        wt[xr] += wt[yr];
    }
    else{
        par[xr] = yr;
        sz[yr] += sz[xr];
        wt[yr] += wt[xr];
    }
}

bool find_(ll x, ll y){
    return getRoot(x) == getRoot(y);
}

ll getWt(ll x){
    ll root = getRoot(x);

    return wt[root];
}

void reset(ll n){
    for(ll i = 0; i <= n; ++i){
        par[i] = i;
        sz[i] = 1;
        wt[i] = 0;
    }
}

int main(){

    fast();

    ll t;
    cin >> t;

    while(t--){
        ll n, c;
        cin >> n >> c;


        read(a, n);

        reset(n);

        for(ll i = 0; i < n; ++i){
            wt[i] = a[i];
        }

        priority_queue <pair <ll, ll>> pq;

        for(ll i = 0; i < n; ++i){
            if(i == 0){
                continue;
            }
            pq.push({(a[i] - (i + 1) * c), i});
        }

        bool ok = 1;

        while(!pq.empty()){
            pair <ll, ll> tp = pq.top();
            pq.pop();

            ll total = wt[0];

            if(total + tp.first >= 0){
                union_(0, tp.second);
            }
            else{
                ok = 0;
                break;
            }
        }

        if(ok){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}





