
#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(int i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(int i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const int mod = 1e9 + 7;
const int mxn = 1e6 + 5;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isTwoPower(int x){
    int a = 1;

    while(a <= x){
        if(a == x) return 1;
        a *= 2;
    }

    return 0;
}

map <int, int> mp;

vector <int> convert(int y, int np){
    vector <int> ans;
    ans.push_back(y);

    while(ans[ans.size() - 1] != np){
        vector <int> fct;
        fct.push_back(1);
        int x = ans[ans.size() - 1];

        for(ll i = 2; i * i <= x; ++i){
            if(x % i == 0){
                if(i == (x / i)){
                    fct.push_back(i);
                }
                else{
                    fct.push_back(i);
                    fct.push_back(x / i);
                }
            }
        }

        int mx = -1;

        for(auto it : fct){
            if(it <= (x - np)){
                mx = max(mx, it);
            }
        }

        ans.push_back(x - mx);
    }

    return ans;

}

int main(){

//    fast();

    int t;
    cin >> t;

    while(t--){
        mp.clear();

        int y;
        cin >> y;

        vector <int> ans;

        int np = 1;

        while(np <= y){
            np *= 2;

            if(np == y) break;
            if(np > y){
                np /= 2;
                break;
            }
        }

        ans = convert(y, np);
        np /= 2;
        while(np != 0){
            ans.push_back(np);
            np /= 2;
        }


        for(int i = 1; i < ans.size(); ++i){
            if(ans[i - 1] % (ans[i - 1] - ans[i]) != 0){
                int zz = 0;
                for(int i = 0; i < 1e18; ++i){
                    zz += i;
                }
            }
            mp[(ans[i - 1] - ans[i])]++;
        }

        for(auto it : mp){
            if(it.second > 2){
                int sz = 0;
                for(int i = 0; i < 1e9; ++i){
                    sz += i;
                }
            }
        }
        cout << ans.size() << "\n";
        print(ans, ans.size());
        cout << "\n";
    }

    return 0;
}


