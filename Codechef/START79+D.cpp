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

int main(){

    fast();
    vector <ll> lst;
    lst.push_back(0);
    for(ll i = 1; i <= 40000; ++i){
        lst.push_back((i * (i + 1)) / 2);
    }

    // print(lst, 10);

    ll n, m, q;
    cin >> n >> m >> q;

    while(q--){
        ll sm;
        cin >> sm;

        if(m == 1){
            bool fnd = 0;
            for(ll i = 0; i <= n; ++i){
                if(lst[i] < sm){
                    continue;
                }
                
                if(binary_search(lst.begin(), lst.begin() + n, lst[i] - sm)){

                    ll st = lower_bound(lst.begin(), lst.begin() + n, lst[i] - sm) - lst.begin();

                    cout << st + 1 << " " << i << "\n";

                    for(ll j = st + 1; j <= i; ++j){
                        cout << 1 << " ";
                    }
                    cout << "\n";

                    fnd = 1;
                    break;

                }
            }

            if(!fnd){
                cout << "-1\n";
            }
        }
        else{

            ll cur = 0;

            ll lst = 1;

            vector <ll> ans;

            for(ll i = 1; i <= n; ++i){
                cur += (m * i);
                lst = i;

                ans.push_back(m);

                if(cur >= sm){
                    break;
                }
            }

            ll de = (cur - sm);

            // cout << "De : " << de << "\n";

            for(ll i = lst; i >= 1; --i){
                ans[i - 1] -= (de / i);
                de -= (de / i) * i;
                

                if(de == 0){
                    break;
                }
            }

            cout << 1 << " " << lst << "\n";
            print(ans, ans.size());
            


        }
    }
    
    return 0;
}