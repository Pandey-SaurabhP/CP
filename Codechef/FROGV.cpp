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

    // fast();

    int n, k, p;
    cin >> n >> k >> p;

    vector <int> a(n);
    read(a, n);

    vector <pair <int, int>> vc(n);

    for(int i = 0; i < n; ++i){
        vc[i] = {a[i], i};
    }

    sort(vc.begin(), vc.end());

    vector <int> par(n);

    for(int i = 0; i < n; ++i) par[i] = i;

    for(int i = 0; i < n; ++i){
        int j = i;

        // cout << j << " ";
        while((j < n - 1) && (vc[j].first + k >= vc[j + 1].first)){
            par[vc[j + 1].second] = vc[i].second;
            ++j;
        }

        // cout << j << "\n";

        i = j;
    }

    while(p--){
        int x, y;
        cin >> x >> y;

        --x;
        --y;

        if(par[x] == par[y]){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    
    return 0;
}