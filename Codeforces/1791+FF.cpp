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

vector <int> segTree(1100005, 0);

void update(int v, int tl, int tr, int l, int r, int add) {
    if(l > r){
        return;
    }

    if(l == tl && r == tr){
        segTree[v] += add;
    } 
    else {
        int tm = (tl + tr) / 2;

        update(v * 2 + 1, tl, tm, l, min(r, tm), add);
        update(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r, add);
    }
}

int get(int v, int tl, int tr, int pos){

    if(tl == tr){
        return segTree[v];
    }

    int tm = (tl + tr) / 2;

    if (pos <= tm){
        return segTree[v] + get(v * 2 + 1, tl, tm, pos);
    }
    else {
        return segTree[v] + get(v * 2 + 2, tm+1, tr, pos);
    }
}

int getSum(int x){
    int ans = 0;

    while(x){
        ans += (x % 10);
        x /= 10;
    }

    return ans;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        for(int i = 0; i < 5 * n; ++i){
            segTree[i] = 0;
        }

        vector <int> a(n);
        read(a, n);

        while(q--){
            int type;
            cin >> type;

            if(type == 1){
                int l, r;
                cin >> l >> r;

                --l; --r;

                update(0, 0, n - 1, l, r, 1);
            }
            else{
                int x;
                cin >> x;

                --x;

                if(a[x] < 10){
                    cout << a[x] << "\n";
                    continue;
                }

                int gx = get(0, 0, n - 1, x);
                int ax = a[x];

                while(gx){
                    ax = getSum(ax);
                    --gx;

                    if(ax < 10){
                        a[x] = ax;
                        break;
                    }
                }

                cout << ax << "\n";

            }
        }


    }
    
    return 0;
}