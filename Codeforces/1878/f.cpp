
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

bool isPossible(int cnt, map <int, int> &fct, int &n){
    if(cnt == n){
        return 1;
    }

    for(auto it : fct){
        cnt /= it.second + 1;
        cnt *= it.second + 2;
    }
}

int main(){
//    initCode();

     fast();


    ll t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        int init = n;


        map <int, int> initMap;

        int tmp = n;
        for(int i = 2; i * i <= n; ++i){
            if(tmp % i == 0){
                initMap[i] = 0;

                while(tmp % i == 0){
                    tmp /= i;
                    ++initMap[i];
                }
            }
        }

        map <int, int> fct = initMap;


        while(q--){
            int type;
            cin >> type;

            if(type == 1){
                int x;
                cin >> x;

                n *= x;

                int tmp = x;

                for(int i = 2; i * i <= n; ++i){
                    if(tmp % i == 0){
                        while(tmp % i == 0){
                            tmp /= i;
                            ++fct[i];
                        }
                    }
                }

                int cnt = 1;

                for(auto it : fct){
                    cnt *= (it + 1);
                }

                if(isPossible(cnt, fct, n)){

                }
            }
            else{
                x = init;
                fct = initMap;
            }
        }
    }

    return 0;
}


