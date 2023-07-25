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

vector <int> sm(mxn);

vector <int> mx(mxn);
vector <int> mn(mxn);

vector <int> smx(mxn);
vector <int> smn(mxn);

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        
        int q;
        cin >> q;

        mx[1] = 1; mn[1] = 0;
        smx[1] = 1; smn[1] = 0;
        sm[1] = 1;

        int u = 2;

        while(q--){
            char type;
            cin >> type;

            if(type == '+'){

                int pu, val;
                cin >> pu >> val;

                sm[u] = sm[pu] + val;
                
                mx[u] = max(mx[pu], sm[u] - mn[pu]);
                mn[u] = min(mn[pu], sm[u]);
                smn[u] = min(smn[pu], sm[u] - smx[pu]);
                smx[u] = max(smx[pu], sm[u]);

                ++u;
            }  
            else{

                int pu, v, k;
                cin >> pu >> v >> k;

                int l = smn[v];
                int r = mx[v];

                if(k >= l && k <= r){
                    cout << "YES\n";
                } 
                else{
                    cout << "NO\n";
                }
            }
        }
    }
    
    return 0;
}