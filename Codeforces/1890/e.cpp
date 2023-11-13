#include <bits/stdc++.h>

using namespace std;

#define read(a, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, n) for(ll i = 0; i < n; ++i) if(i == n - 1){ cout << a[i] << " "; } else { cout << a[i] << ' '; }

typedef long long int ll;
typedef long double ld;

const ll mod = 1e9 + 7;
const ll mxn = 2e5 + 5;
const ll INF = INT_MAX;

void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


int main(){

//    fast();

    ll T;
    cin >> T;

    while(T--){

        int n, m, k;
        cin >> n >> m >> k;

        vector <int> pre(n + 2, 0);

        vector <pair <int, int>> inp(m);
        vector <set <int>> start(n + 2);
        vector <set <int>> end_(n + 2);

        for(int i = 0; i < m; ++i){
            int l, r;
            cin >> l >> r;

            --l, --r;

            inp[i] = {l, r};

            pre[l]++;
            pre[r + 1]--;

            start[l].insert(i);
            end_[r + 1].insert(i);
        }


        build(pre, 0, 0, n - 1);
        print(t, 15);

        vector <set <int>> fc(n + 2);
        set <int> tmp = fc[0];

        for(int i = 0; i < n; ++i){

            for(auto it : end_[i]){
                if(tmp.count(it)){
                    tmp.erase(it);
                }
            }

            for(auto it : start[i]){
                tmp.insert(it);
            }

            if(tmp.size() <= 2){
                fc[i] = tmp;
            }
        }

        for(int i = 0; i < n + 1; ++i){
            cout << i << " : ";
            for(auto it : fc[i]){
                cout << it << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        vector <int> cntLess(n + 1, 0);cntLess[0] = (pre[0] <= 2);
        vector <int> cntOne(n + 1, 0); cntOne[0] = (pre[0] <= 1);

        for(int i = 1; i < n; ++i){
            cntLess[i] = cntLess[i - 1] + (pre[i] <= 2);
            cntOne[i] = cntOne[i - 1] + (pre[i] <= 1);
        }

        int gbAns = 0;

        vector <pair <int, int>> ids;

        for(int i = 0; i < n; ++i){
            if(pre[i] == 2){
                // Find and remove

                // Remove all contributions of i
                int ans = 0;

                for(auto it : fc[i]){
                    if(it.first == 0){
                        ans += cntLess[it.second];
                    }
                    else ans += cntLess[it.second] - cntLess[it.first - 1];
                }

                gbAns = max(ans, gbAns);

            }
            else if(pre[i] == 1){
                for(auto it : fc[i]){
                    ids.push_back(it.first, it.second);
                    ans += cntLess[]
                }
            }
        }
    }

    return 0;
}






