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

bool cmp(vector <int> a, vector <int> b){
    if(a[0] < b[0]){
        return 1;
    }
    else if(a[0] == b[0]){
        if(a[3] < b[3]){
            return 1;
        }
    }

    return 0;
}

int main(){

    fast();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <vector <int>> a(n, vector <int> (4));

        for(int i = 0; i < n; ++i){
            cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3]; 
        }

        if(n == 1){
            int q; cin >> q;

            while(q--){
                int x;
                cin >> x;

                if(x >= a[0][0] && x <= a[0][1]){
                    cout << max(x, a[0][3]) << " ";
                }
                else{
                    cout << x << " ";
                }
            }

            cout << "\n";
            continue;
        }

        sort(a.begin(), a.end(), cmp);

        // for(int i = 0; i < n; ++i){
        //     cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << " " << a[i][3] << "\n";
        // }

        int i = 0, j = 1;

        vector <vector <int>> nw;
        vector <int> tmp = a[i];

        while(j < n){
            if(tmp[3] < a[j][0]){
                nw.push_back(tmp);
                tmp = a[j];

                i = j;
                ++j;
            }
            else{
                tmp[1] = max(tmp[1], a[j][1]);
                tmp[2] = min(tmp[2], a[j][2]);
                tmp[3] = max(tmp[3], a[j][3]);

                ++j;
            }
        }

        nw.push_back(tmp);

        // for(auto it : nw){
        //     for(auto jt : it){
        //         cout << jt << " ";
        //     } 
        //     cout << "\n";
        // }


        for(int i = 1; i < nw.size(); ++i){
            if(nw[i][0] <= nw[i - 1][1]){
                nw[i - 1][1] = nw[i][0] - 1;
            }

            if(nw[i - 1][1] < nw[i - 1][0]){
                nw[i - 1][0] = nw[i - 1][1] = -1;
            }
        }

        sort(nw.begin(), nw.end(), cmp);

        vector <int> bin;

        for(int i = 0; i < nw.size(); ++i){
            bin.push_back(nw[i][0]);
        }

        // for(auto it : nw){
        //     for(auto jt : it){
        //         cout << jt << " ";
        //     } 
        //     cout << "\n";
        // }

        int q;
        cin >> q;


        while(q--){
            int x;
            cin >> x;

            auto id = upper_bound(bin.begin(), bin.end(), x) - bin.begin();
            --id;

            // cout << id << "\n";

            if(id == -1){
                // Element
                cout << x << " ";
                continue; 
            }

            if(x >= nw[id][0] && x <= nw[id][1]){
                cout << max(x, nw[id][3]) << " ";
            }
            else{
                cout << x << " ";
            }

        }

        cout << "\n";
    }
    
    return 0;
}