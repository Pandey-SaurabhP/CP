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

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector <int> a(n);
        read(a, n);

        vector <int> b(n);
        read(b, n);

        vector <pair <int, int>> at(n);
        vector <pair <int, int>> bt(n);


        for(int i = 0; i < n; ++i){
            at[i] = {a[i], i};
            bt[i] = {b[i], i};
        }

        sort(at.begin(), at.end());
        sort(bt.begin(), bt.end());

        map <int, vector <int>> mp;
        map <int, int> id;

        for(int i = 0; i < n; ++i){
            mp[at[i].first].push_back(bt[i].first);
            id[at[i].first] = 0;
        }

        // for(auto it : mp){
        //     cout << it.first << " : ";
        //     print(it.second, it.second.size());
        // }

        for(int i = 0; i < n; ++i){
            cout << mp[a[i]][id[a[i]]] << " ";
            id[a[i]] += 1;
        }

        cout << "\n";



    }
    
    return 0;
}