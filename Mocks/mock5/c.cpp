

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

int adj[101][101];
int floydMax[101][101];
int floydMin[101][101];


bool checkCoherence(int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(adj[i][j] != floydMin[i][j]){
                return 0;
            }
        }
    }

    return 1;
}

int main(){

    fast();

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> adj[i][j];

            floydMin[i][j] = floydMax[i][j] = adj[i][j];
        }
    }


    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                floydMin[i][j] = min(floydMin[i][j], floydMin[i][k] + floydMin[k][j]);
            }
        }
    }

    if(!checkCoherence(n)){
        cout << -1 << "\n";
    }
    else{
        int cnt = 0;
        set <pair <int, int>> st;

        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    if((i != j) && (i != k && j != k) && (floydMin[i][j] == floydMin[i][k] + floydMin[k][j])){
                            st.insert({i, j});
                            st.insert({j, i});
//                        cout << i << " " << k << " " << j << "\n";
                        ++cnt;
                    }
                }
            }
        }


        cout << st.size() / 2;

//        cout << "\n";
    }



    return 0;
}

//4
//0 1 2 4
//1 0 1 3
//2 1 0 2
//4 3 2 0


