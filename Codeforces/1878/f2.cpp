#include <bits/stdc++.h>
using namespace std;

bool gcdMatch(map <int, int> mp, int x){
    for(int i = 2; i * i <= x; ++i){
        while(x % i == 0){
            if(mp[i] > 0){
                --mp[i];
            }
            else{
                return 0;
            }

            x /= i;
        }
    }

    if(x >= 2){
        if(mp[x] > 0){
            --mp[x];
        }
        else{
            return 0;
        }
    }

    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long t;
    cin >> t;

    while(t--){
        long long n, q;
        cin >> n >> q;

        long long start = n;

        map <int, int> initFact;

        for(int i = 2; i * i <= start; ++i){
            if(start % i == 0){
                initFact[i] = 0;

                while(start % i == 0){
                    initFact[i]++;
                    start /= i;
                }
            }
        }
        if(start > 1){
            initFact[start]++;
        }

        map <int, int> fact = initFact;

        while(q--){
            long long type;
            cin >> type;

            if(type == 1){
                long long x;
                cin >> x;

                for(int i = 2; i * i <= x; i += 2){
                    while(x % i == 0){
                        fact[i]++;
                        x /= i;
                    }
                }
                if(x >= 2){
                    fact[x]++;
                }

                int cnt = 1;
                for(auto it : fact){
                    cnt *= (it.second + 1);
                }

                if(gcdMatch(fact, cnt)){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
            }
            else{
                fact = initFact;
            }
        }

        cout << "\n";
    }

    return 0;
}
