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

class avlTree{
public:
    vector <vector <int>> adj;
    vector <int> left, right;
    vector <int> imbalance;
    int root;
    int cntNodes;
    

    avlTree(int n){
        ++n;

        adj.resize(n);
        left.resize(n);
        right.resize(n);
        imbalance.resize(n);

        cntNodes = 0;
        root = -1;
    }

    void insert(int root, int x){
        if(cntNodes == 0){
            root = x;
            ++cntNodes;
        }


    }
};

int main(){

    // fast();

    int t;
    cin >> t;

    while(t--){
        
    }
    
    return 0;
}