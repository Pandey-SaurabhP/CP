
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define prll(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll tx, ty, act;

int getAns(int cur, int target){

    queue <int> q;
    q.push(cur);
    q.push(-1);

    int d = 0;

    while(!q.empty()){
        int tp = q.front();
        q.pop();

        if(tp == target){
            return d;
        }

        if(tp == -1){

            if(q.back() != -1){
                q.push(-1);
            }

            ++d;

            continue;
        }

        q.push(tp / 2);
        q.push(tp + ((act - tp) / 2));
    }

    return -1;
}


int main(){
//    fast();
    ll n;
    cin >> n >> tx >> ty;

    act = pow(2, n);

    int a1 = getAns(act / 2, tx);
    int a2 = getAns(act / 2, ty);

    cout << max(a1, a2);


    return 0;
}








