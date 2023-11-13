
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << endl; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 1e5 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main(){
//    initCode();

     fast();

//    sieve();
//
//    cout << "Hello\n";
//    cout << primeList.size() << "\n";

    ll t;
    cin >> t;

    while(t--){
        ll n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector <int> l(k);
        vector <int> r(k);

        read(l, k);
        read(r, k);

        for(int i = 0; i < k; ++i){
            --l[i];
            --r[i];
        }

        vector <vector <int>> vc(k);

        for(int i = 0; i < k; ++i){
            int sz = r[i] - l[i] + 1;
            vector <int> tmp(sz + 3);
            vc[i] = tmp;
        }

//        cout << "LR : \n";
//        print(l, k);
//        print(r, k);
//
//        cout << "\n";

        int q;
        cin >> q;

        vector <int> qr(q);
        for(int i = 0; i < q; ++i){
            cin >> qr[i];
        }

//        cout << "Hello\n";

        for(int i = 0; i < q; ++i){
            int x = qr[i];
            --x;

            int id = upper_bound(l.begin(), l.end(), x) - l.begin();
            --id;

//            cout << "XID : " << x << " " << id << "\n";

            int a = min(x, r[id] + l[id] - x);
            int b = max(x, r[id] + l[id] - x);

            b -= l[id];
            a -= l[id];

//            cout << "AB : " << a << " " << b << "\n";

            vc[id][a]++;
            vc[id][b + 1]--;
        }

//        for(int i = 0; i < k; ++i){
//            for(int j = 0; j < vc[i].size(); ++j){
//                cout << vc[i][j] << " ";
//            }
//
//            cout << "\n";
//        }
//        cout << "\n";

        for(int i = 0; i < k; ++i){
            for(int j = 1; j < vc[i].size(); ++j){
                vc[i][j] = vc[i][j - 1] + vc[i][j];
            }
        }

//        for(int i = 0; i < k; ++i){
//            for(int j = 0; j < vc[i].size(); ++j){
//                cout << vc[i][j] << " ";
//            }
//
//            cout << "\n";
//        }
//        cout << "\n";

        for(int i = 0; i < k; ++i){
            for(int j = 0; j < (r[i] - l[i] + 1) / 2; ++j){
                if(vc[i][j] % 2 == 1){
//                    cout << i << " " << j << " : " << j + l[i] << " " << (r[i] - l[i]) - j + l[i] << "\n";
                    swap(s[j + l[i]], s[(r[i] - l[i]) - j + l[i]]);
                }
            }
        }

        cout << s<< "\n";
    }

    return 0;
}


