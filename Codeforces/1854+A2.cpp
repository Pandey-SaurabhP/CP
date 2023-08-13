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

vector <pair <int, int>> op1, op2;

int countNegOps(vector <int> a, int n){
    int mnId = 0;
    int mxId = 0;

    int ans = 0;

    for(int i = 1; i < n; ++i){
        if(a[i] < a[mnId]){
            mnId = i;
        }

        if(a[i] > a[mxId]){
            mxId = i;
        }
    }

    while(-a[mnId] < a[mxId]){
        
        a[mnId] *= 2;
        op1.push_back({mnId, mnId});
        ++ans;
    }

    for(int i = 0; i < n; ++i){
        if(a[i] > 0){
            ++ans;
            op1.push_back({i, mnId});
            a[i] += a[mnId];
        }
    }

    for(int i = n - 2; i >= 0; --i){
        op1.push_back({i, i + 1});
    }

    return ans + n - 1;
}

int countPosOps(vector <int> a, int n){
    int mnId = 0;
    int mxId = 0;

    int ans = 0;

    for(int i = 1; i < n; ++i){
        if(a[i] < a[mnId]){
            mnId = i;
        }

        if(a[i] > a[mxId]){
            mxId = i;
        }
    }


    while(a[mxId] < -a[mnId]){
        a[mxId] *= 2;
        op2.push_back({mxId, mxId});
        ++ans;
    }

    for(int i = 0; i < n; ++i){
        if(a[i] < 0){
            ++ans;
            op2.push_back({i, mxId});
            a[i] += a[mxId];
        }
    }

    for(int i = 1; i < n; ++i){
        op2.push_back({i, i - 1});
    }

    return ans + n - 1;
}

bool allPos(vector <int> &a){
    for(auto it : a){
        if(it < 0) return 0;
    }

    return 1;
}

bool allNeg(vector <int> &a){
    for(auto it : a){
        if(it > 0) return 0;
    }

    return 1;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        op1.clear(); op2.clear();
        int n;
        cin >> n;

        vector <int> a(n);
        read(a, n);

        if(allPos(a)){
            cout << n - 1 << "\n";
            for(int i = 1; i < n; ++i){
                cout << i + 1 << " " << i << "\n";
            }
        }
        else if(allNeg(a)){
            cout << n - 1 << "\n";

            for(int i = n - 2; i >= 0; --i){
                cout << i + 1 << " " << i + 2 << "\n";
            }
        }
        else{
            int cneg = countNegOps(a, n);
            int cpos = countPosOps(a, n);

            if(cneg < cpos){
                cout << op1.size() << "\n";
                for(auto it : op1){
                    cout << it.first + 1 << " " << it.second + 1 << "\n";
                }
            }
            else{
                cout << op2.size() << "\n";
                for(auto it : op2){
                    cout << it.first + 1 << " " << it.second + 1 << "\n";
                }
            }
        }


    }
    
    return 0;
}