#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

// Constants
const ll mxn = 1e6 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
void floodFill(vector <int> &a, vector <int> &b, int i, int val, int n, vector <bool> &vis){

    if(i < 0 || i >= n){
        return;
    }

    if(a[i] > val){
        return;
    }
    if(a[i] > b[i]){
        return;
    }
    if(b[i] < val){
        return;
    }

    if(vis[i]) return;

    vis[i] = 1;
    a[i] = val;

    floodFill(a, b, i - 1, val, n, vis);
    floodFill(a, b, i + 1, val, n, vis);
}


void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    read(a, i, n);

    vector <int> b(n);
    read(b, i, n);

    priority_queue <int, vector <int>, greater <int>> pq;

    for(auto it : b){
        pq.push(it);
    }

    map <int, vector <int>> mp;

    for(int i = 0; i < n; ++i){
        mp[a[i]].pb(i);
    }

    // while(!pq.empty()){
    //     vector <bool> vis2(n, 0);

    //     int tp = pq.top();
    //     pq.pop();
    for(auto it : mp){
        for(int i = 0; i < it.ss.size(); ++i){
            floodFill(a, b, it.ss[i], it.ff, n, vis2);
        }
    }
    // }

    bool doable = 1;

    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            doable = 0;
            break;
        }
    }

    if(doable){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    
    fast();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}