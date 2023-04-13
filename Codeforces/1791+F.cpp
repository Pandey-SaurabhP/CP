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

        vector <int> a(n);
        read(a, n);

        vector <int> op(n, 0);
        vector <int> qrs(n + 1, 0);
        vector <bool> sd(n + 1, 0);

        while(q--){
            int type;
            cin >> type;

            if(type == 1){
                int l, r;
                cin >> l >> r;
 
                --l;
                --r;

                qrs[l] += 1;
                qrs[r + 1] -= 1;
            }
            else{
                int x;
                cin >> x;

                --x;

                if(sd[x]){
                    cout << a[x] << "\n";
                }
                else{
                    int cr = 0;

                    for(int i = 0; i < n; ++i){
                        cr += qrs[i];
                        op[i] = op[i] + cr;

                        qrs[i] = 0;
                    }

                    // print(op, n + 1);

                    while(op[x]){
                        a[x] = getSum(a[x]);
                        --op[x];

                        if(a[x] < 10){
                            op[x] = 0;
                            break;
                        }
                    }

                    if(a[x] < 10){
                        sd[x] = 1;
                    }
                    
                    cout << a[x] << "\n";
                }
            }
        }
    }
    
    return 0;
}