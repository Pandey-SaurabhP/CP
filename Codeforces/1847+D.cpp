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

void printPQ(priority_queue <int> pq){
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}
int main(){

    // fast();

    int n, m, q;
    cin >> n >> m >> q;

    string s;
    cin >> s;

    vector <int> st(n, INT_MAX);
    vector <int> ed(n, INT_MAX);

    int i = 1;

    while(m--){
        int l, r;
        cin >> l >> r;
        --l; --r;

        st[l] = min(i, st[l]);
        ed[r] = min(i, ed[r]);

        ++i;
    }

    priority_queue <int> pq;
    vector <int> id(n, -1);

    for(int i = 0; i < n; ++i){
        printPQ(pq);

        if(st[i] != INT_MAX){
            pq.push(st[i]);
        }

        if(!pq.empty()) id[i] = pq.top();
        
        if(!pq.empty() && ed[i] == pq.top()){
            pq.push(ed[i]);
        }
    }

    
    print(id, n);

    while(q--){
        int x;
        cin >> x;
    }
    
    return 0;
}