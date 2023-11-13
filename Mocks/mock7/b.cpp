#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isSorted(vector <int> &a){
    int n = a.size();

    for(int i = 1; i < n; ++i){
        if(a[i] < a[i - 1]){
            return 0;
        }
    }

    return 1;
}

int main(){

//    fast();

    int n, k;
    cin >> n >> k;

    vector <pair <int, int>> vc(n);

    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;

        --x; --y;

        vc[i] = {x, y};
    }

    vector <vector <int>> colors(k);

    for(auto it : vc){
        pair <int, int> pp = it;
        colors[pp.second].push_back(pp.first);
    }

    for(int i = 0; i < k; ++i){
        sort(colors[i].begin(), colors[i].end());
    }

    vector <int> pointers(k, 0);

    vector <int> b(n);

    for(int i = 0; i < n; ++i){
        b[i] = colors[vc[i].second][pointers[vc[i].second]++];
    }

//    for(auto it : b){
//        cout << it << " ";
//    }

    if(isSorted(b)){
        cout << "Y";
    }
    else{
        cout << "N";
    }

    return 0;
}


